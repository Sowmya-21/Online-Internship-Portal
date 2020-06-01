#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
struct user
{
	int id;
	char sem[30];
	char name[50],emailid[30],colname[50],regno[50],branch[50],pw[50],lan[50];
	char age[50];
	char phno[50];
	char cgpa[50];
	
}k1;
struct userintdomain
{
int id;
int uid;
int internid;
char batch[50];
struct userintdomain *next;
};
struct intern{
	int id;
	char name[50];
	char des[50];
	char req[50];
	char branch[50];
	char sem[50],out[50];
	int stud;
};
int checklog(char[50],char[50]);
int checkname(char[50]);
int checkemail(char[50]);
int checkphno(char[50]);
int checkregno(char[50]);
int checksem(char[50]);
int checkcolname(char[50]);
int checkbranch(char[50]);
int checkage(char[50]);
int checkpw(char[50]);
int checkconfirmpw(char[50]);
void signin();
void signup();
void allott(int i,int userid);
void assign();
//void branch();
void showBatch(int id);
int fif(int j);
int main()
{
	int a;
	do
	{
	system("cls");
	printf("-----------------Welcome to I-BOX--------------\n");
	printf("Enter a choice\n");
	printf("1. Sign up\n2. Sign in\n");
	printf("Press 0 for exit\n");
	scanf("%d",&a);
	//printf("%d",a);
	switch(a)
	{
	case 1:
		system("cls");
	signup();
	break;
	case 2:
		system("cls");
	signin();
	break;
	
	case 0:
	exit(0);
	break;
	
	default:
	printf("\n           Enter Valid choice           \n")	;
	}
}
	while(1);
	return 0;
}

void signup()
{
	struct user s,a;
	FILE *fp,*fp1;
	fp=fopen("file.txt","a");
	ctrl1:
	printf("Enter name\n");
	scanf("%s",s.name);
	if(checkname(s.name)==0)
	goto ctrl1;
	ctrl2:
	printf("Enter age\n");
	scanf("%s",s.age);
	if(checkage(s.age)==0)
	goto ctrl2;
	ctrl3:
	printf("Enter phone number\n");
	scanf("%s",s.phno);
	if(checkphno(s.phno)==0)
	goto ctrl3;
	ctrl4:
	printf("Enter E-mail ID\n");
	scanf("%s",s.emailid);
	if(checkemail(s.emailid)==0)
	goto ctrl4;
	ctrl5:
	printf("Enter College Name\n");
	getchar();
	gets(s.colname);
	if(checkcolname(s.colname)==0)
	goto ctrl5;
	ctrl6:
	printf("Enter Registration number\n");
	scanf("%s",s.regno);
	if(checkregno(s.regno)==0)
	goto ctrl6;
	ctrl7:
	printf("Enter Branch\n");
	getchar();
	gets(s.branch);
	//scanf("%[^\n]%*c", s.branch); 
	if(checkbranch(s.branch)==0)
	goto ctrl7;
	ctrl8:
	printf("Enter Semester\n");
	scanf("%s",s.sem);
	if(checksem(s.sem)==0)
	goto ctrl8;
	ctrl10:
	printf("Enter CGPA : \n");
	scanf("%s",s.cgpa);
	if(checkcgpa(s.cgpa)==0)
	goto ctrl10;
	ctrl9:
	printf("Enter Password :\n");
	scanf("%s",s.pw);
	if(checkpw(s.pw)==0)
	goto ctrl9;
	char cpw[50];
	//////////////////////////
	printf("Enter Language :\n");
	scanf("%s",s.lan);
	//////////////////////////
	printf("\nConfirm password :\n");
	scanf("%s",cpw);
	if(strcmp(s.pw,cpw))
	{
printf("Password Mismatch\n");	
	goto ctrl9;
}
printf("Your Account has been created!");
int count=1000;
/////////////////////////
fp1=fopen("file.txt","r");
while(fread(&a,sizeof(struct user),1,fp1))
	{
		count++;
	}
s.id=count;
fclose(fp1);
//////////////////////////
printf("Your ID is %d\n",s.id);
system("pause");

if (fp != NULL) {
    fwrite(&s, sizeof(struct user), 1, fp);
    fclose(fp);
}

	}
	
void signin()
{
		FILE *fp;
		int count=0;
		int choice,ch2,ch3;
		struct intern s;
		char eid[50],pw[50];
		printf("Enter email address : \n");
		scanf("%s",eid);
		printf("Enter the password :\n");
		scanf("%s",pw);
		system("cls");
	if(strcmp(eid,"admin")==0 && strcmp(pw,"admin")==0)
		{
			do{
			system("cls");
			printf("Welcome Admin,\n\n");
			printf("1.Add Internship\n");
			printf("2.Create Batch\n");
			printf("3. Logout");
			scanf("%d",&choice);
			switch(choice)
				{
					case 1:
						count=find();
						printf("Enter Internship name\n");
						getchar();
						gets(s.name);
						printf("Enter Description\n");
						gets(s.des);
						printf("Enter Requirement");
						gets(s.req);
						printf("Enter the outcomes of internship\n");
						gets(s.out);
						printf("Enter branch\n");
						gets(s.branch);
						printf("Enter semester\n");
						gets(s.sem);
						printf("Enter number of students per batch\n");
						scanf("%d",&s.stud);
						//FILE *fp;
						fp=fopen("internshipdetails.txt","a");
						s.id=count+1;
						fwrite(&s,sizeof(struct intern),1,fp);
						fclose(fp);
						
					case 3:
						return;
						break;
					
					case 2:
						printf("Select Internship\n");
						assign();
						struct userintdomain temp;
						struct userintdomain *head=NULL,*head2=NULL;
						//FILE *fp;
						printf("Enter your choice\n");
						scanf("%d",&ch2);
						printf("Choice criteria\n");
						printf("1. First in First\n2. Based on branch\n3. Based on semester\n4. Finalize batch\n");
						scanf("%d",&ch3);
						switch(ch3)
							{
								case 1:
									fif(ch2);
									break;
/////////////////////////////////////////////////////////////////////////////////////////////////////									
								case 2:
									
									fp=fopen("internshipdetails.txt","r");
									char bran[50];
									while(fread(&s,sizeof(struct intern),1,fp)>0)
										{
											if(s.id==ch2)
												{
													strcpy(bran,s.branch);
												}
										}
									fclose(fp);
									//printf("%s",bran);
									fp=fopen("userintern.txt","r");
									struct userintdomain *trav=head,*trav2=NULL;
									while(fread(&temp,sizeof(struct userintdomain),1,fp))
										{
											struct userintdomain *NN=(struct userintdomain *)malloc(sizeof(struct userintdomain));
											trav=head;
											strcpy(NN->batch,temp.batch);
											NN->id=temp.id;
											NN->internid=temp.internid;
											NN->next=NULL;
											NN->uid=temp.uid;
											if(head==NULL)
												{
													head=NN;
												}
											else
												{
													while(trav->next!=NULL)
														{
															trav=trav->next;
														}
													trav->next=NN;
												}
										}
									fclose(fp);
									trav=head;
									/*while(trav!=NULL)
										{
											printf("%d ",trav->internid);
											trav=trav->next;
										}*/
									//	printf("\n");
									trav=head;
									while(trav!=NULL)
										{
											if(trav->id==ch2)
												{
													trav2=head2;
													struct userintdomain *NN=(struct userintdomain *)malloc(sizeof(struct userintdomain));
													strcpy(NN->batch,trav->batch);
													NN->id=trav->id;
													NN->internid=trav->internid;
													NN->next=NULL;
													NN->uid=trav->uid;
													if(head2==NULL)
														{
															head2=NN;
														}
													else
														{
															//trav2=head2;
															while(trav2->next!=NULL)
																{
																	trav2=trav2->next;
																}
															trav2->next=NN;
														}
												}
											trav=trav->next;
										}
									trav2=head2;
									struct userintdomain *sort=head;
									/*while(trav2!=NULL)
										{
											printf("%d ",trav2->internid);
											trav2=trav2->next;
										}*/
								//	printf("hi\n");
									int i=0;
									struct intern z;
									int bno;
									int t=0;
									int op=0;
									FILE *fp1;
									fp1=fopen("internshipdetails.txt","r");
									while(fread(&z,sizeof(struct intern),1,fp1))
										{
											if(ch2==z.id)
												{
													//printf("hi2\n");
													bno=z.stud;
													break;
												}
										}
									fclose(fp1);
									struct user us;
									trav2=head2;
									while(trav2!=NULL)
										{
											fp=fopen("file.txt","r");
										//	printf("hi3\n");
											while(fread(&us,sizeof(struct user),1,fp)>0)
												{
												//	printf("Hi3\n");
													if(trav2->uid==us.id)
														{
														//	printf("hi4\n");
															if(strcmp(us.branch,bran)==0)
																{
																	//	printf("hi5\n");
																	trav2->batch[0]=64+ch2;
																	trav2->batch[1]=49+t;
																	trav2->batch[2]='\0';
																	op++;
																}
															if(op>=bno)
																{
																	t++;
																}
															op=op%bno;
														}
												}
											fclose(fp);
											trav2=trav2->next;
										}
									trav2=head2;
									while(trav2!=NULL)
										{
											fp=fopen("file.txt","r");
											while(fread(&us,sizeof(struct user),1,fp))
												{
													if(trav2->uid==us.id)
														{
															if(strcmp(us.branch,bran)!=0)
																{
																	trav2->batch[0]=64+ch2;
																	trav2->batch[1]=49+t;
																	trav2->batch[2]='\0';
																	op++;
																}
															if(op>=bno)
																{
																	t++;
																}
															op=op%bno;
														}
												}
											fclose(fp);
											trav2=trav2->next;
										}
										trav2=head2;
										while(trav2!=NULL)
											{
												printf("%s",trav2->batch);
												trav2=trav2->next;
											}
									system("pause");
									FILE *fpp;
									trav=head;
									trav2=head2;
/////////////////////////////////////////////////////////  WRITING /////////////////////////////////////////////
									fpp=fopen("userintern.txt","w");
										while(trav!=NULL)
											{
												if(trav->id!=ch2)
													{
														fwrite(trav,sizeof(struct userintdomain),1,fpp);
													}
												trav=trav->next;
											}
										while(trav2!=NULL)
											{
												fwrite(trav2,sizeof(struct userintdomain),1,fpp);
												trav2=trav2->next;
											}
										fclose(fpp);
									break;
									
							case 3:
								
									fp=fopen("internshipdetails.txt","r");
									while(fread(&s,sizeof(struct intern),1,fp)>0)
										{
											if(s.id==ch2)
												{
													strcpy(bran,s.sem);
												}
										}
									fclose(fp);
									//printf("%s",bran);
									head=NULL;
									fp=fopen("userintern.txt","r");
									trav=head;
									trav2=NULL;
									head2=NULL;
									while(fread(&temp,sizeof(struct userintdomain),1,fp))
										{
											struct userintdomain *NN=(struct userintdomain *)malloc(sizeof(struct userintdomain));
											trav=head;
											strcpy(NN->batch,temp.batch);
											NN->id=temp.id;
											NN->internid=temp.internid;
											NN->next=NULL;
											NN->uid=temp.uid;
											if(head==NULL)
												{
													head=NN;
												}
											else
												{
													while(trav->next!=NULL)
														{
															trav=trav->next;
														}
													trav->next=NN;
												}
										}
									fclose(fp);
									trav=head;
									/*while(trav!=NULL)
										{
											printf("%d ",trav->internid);
											trav=trav->next;
										}
										printf("\n");*/
									trav=head;
									while(trav!=NULL)
										{
											if(trav->id==ch2)
												{
													trav2=head2;
													struct userintdomain *NN=(struct userintdomain *)malloc(sizeof(struct userintdomain));
													strcpy(NN->batch,trav->batch);
													NN->id=trav->id;
													NN->internid=trav->internid;
													NN->next=NULL;
													NN->uid=trav->uid;
													if(head2==NULL)
														{
															head2=NN;
														}
													else
														{
															//trav2=head2;
															while(trav2->next!=NULL)
																{
																	trav2=trav2->next;
																}
															trav2->next=NN;
														}
												}
											trav=trav->next;
										}
									trav2=head2;
									sort=head;
									/*while(trav2!=NULL)
										{
											printf("%d ",trav2->internid);
											trav2=trav2->next;
										}*/
									//printf("hi\n");
									i=0;
									//z;
									//bno;
									t=0;
									op=0;
									fp1=fopen("internshipdetails.txt","r");
									while(fread(&z,sizeof(struct intern),1,fp1))
										{
											if(ch2==z.id)
												{
													//printf("hi2\n");
													bno=z.stud;
													break;
												}
										}
									fclose(fp1);
									trav2=head2;
									while(trav2!=NULL)
										{
											fp=fopen("file.txt","r");
											
											while(fread(&us,sizeof(struct user),1,fp)>0)
												{
													
													if(trav2->uid==us.id)
														{
															
															if(strcmp(us.sem,bran)==0)
																{
																	//printf("1-%s\n",us.name);
																		//printf("hi5\n");
																	trav2->batch[0]=64+ch2;
																	trav2->batch[1]=49+t;
																	trav2->batch[2]='\0';
																	op++;
																}
															if(op>=bno)
																{
																	t++;
																}
															op=op%bno;
														}
												}
											fclose(fp);
											trav2=trav2->next;
										}
									trav2=head2;
									while(trav2!=NULL)
										{
											fp=fopen("file.txt","r");
											while(fread(&us,sizeof(struct user),1,fp))
												{
													if(trav2->uid==us.id)
														{
															if(strcmp(us.sem,bran)!=0)
																{
																	//printf("2-%s\n",us.name);
																	trav2->batch[0]=64+ch2;
																	trav2->batch[1]=49+t;
																	trav2->batch[2]='\0';
																	op++;
																}
															if(op>=bno)
																{
																	t++;
																}
															op=op%bno;
														}
												}
											fclose(fp);
											trav2=trav2->next;
										}
										trav2=head2;
										while(trav2!=NULL)
											{
												printf("%s ",trav2->batch);
												trav2=trav2->next;
											}
										trav2=head2;
										trav=head;
									system("pause");
/////////////////////////////////////////////////////////  WRITING /////////////////////////////////////////////
									fpp=fopen("userintern.txt","w");
										while(trav!=NULL)
											{
												if(trav->id!=ch2)
													{
														fwrite(trav,sizeof(struct userintdomain),1,fpp);
													}
												trav=trav->next;
											}
										while(trav2!=NULL)
											{
												fwrite(trav2,sizeof(struct userintdomain),1,fpp);
												trav2=trav2->next;
											}
										fclose(fpp);
									break;
								
							case 4:
								printf("");
							}
					break;		
				}
			
		}while(1);
}
	else if(checklog(eid,pw)==1)
	{
		//fp=fopen("file.txt","r");
		printf("Welcome to I-BOX\n");
		printf("You are Logged in\n");
	t1:	printf("Your Details");
	//	printf("\nID = %s",k1.id);
		printf("\nName = %s",k1.name);
		printf("\nAge = %s",k1.age);
		printf("\nPhone number = %s",k1.phno);
		printf("\nSemester = %s",k1.sem);
		printf("\nCGPA = %s",k1.cgpa);
		printf("\nStream = %s",k1.branch);
		printf("\nCollege Name = %s\n",k1.colname);
		printf("-----------------Please Select An Option--------------\n");
		printf("1 - Select an Internship!\n");
		printf("2 - Done for today. Log me Out.\n");
		printf("3 - View batch.\n");
		//printf("3 - Show Internship Information\n");
		printf("Please Select - \n");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					system("cls");
					assign();
					scanf("%d",&ch2);
					allott(ch2,k1.id);
					system("pause");
					system("cls");
					goto t1;
					break;
					
				case 2:
					system("cls");
					printf("Thank You!");
					system("pause");
					break;	
					
				case 3:
					system("cls");
					showBatch(k1.id);
					system("pause");
					goto t1;
			}



		//s=k1;
		//fopen("file.txt","r");
		//rewind(fp);
		//	while(fread(&s,sizeof(struct user),1,fp));
			//{
			//		printf("hello");
			//	if(strcmp(eid,s.emailid)==0)
				//	{
							
					//}
					
			//}
			//fclose(fp);
		
	}
	else
		{
			printf("No such ID exists.\n");
			system("pause");
		}
    }
void showBatch(int id)
	{
		FILE *fp;
		fp=fopen("userintern.txt","r");
		struct userintdomain s;
		while(fread(&s,sizeof(struct userintdomain),1,fp))
			{
				if(id==s.uid)
					{
						printf("Batch = %s InternshipID=%d\n",s.batch,s.id);
					}
			}
		fclose(fp);
	}
		
		
int checklog(char id[50],char pw[50])
	{
		struct user s;
		FILE *fp;
		fp=fopen("file.txt","r");
		while(fread(&s,sizeof(s),1,fp))
			{
				if(strcmp(s.emailid,id)==0 && strcmp(s.pw,pw)==0)
				{
				k1=s;
				fclose(fp);
				return 1;
				}
			}
		fclose(fp);
		return 0;
}


	

int checkname(char name[50])
	{
		struct user s;
		FILE *fp;
		fp=fopen("file.dat","rb");
		if(name[0]==' ')
			{
				printf("Name can't be empty! Re-enter Name\n");
				return 0;
			}
		
		
				//fscanf("%s %s %s %s %s %s %s %s %s %s %s",s.name,s.age,s.phno,s.emailid,s.colname,s.regno,s.branch,s.sem,s.pw,s.lan,s.cgpa);
				while(fread(&s, sizeof(struct user), 1, fp));
			{
					
				if(strcmp(name,s.name)==0)
					{
						fclose(fp);
						printf("This Name already exists!\n");
						return 0;
					}
			}
		return 1;
	}
int checkage(char age[50])

	{
		int i;
		for(i=0;i<strlen(age);i++)
			{
				if(!(age[i]>=48 && age[i]<=57))
				{
				printf("Age should be numberic's\n");
				return 0;
				}
			}
		return 1;
	}
int checkemail(char email[50])
	{
		struct user s;
		FILE *fp;
		int i,j,flag=0;
		for(i=0;i<strlen(email);i++)
			{
				if(email[i]=='@')
					{
						for(j=i;j<strlen(email);j++)
							{
								if(email[j]=='.')
									{
										flag=1;
									}
							}
					}
			}
		if(flag==0)
			{
				printf("Enter a Valid Email ID\n");
				return 0;
			}
		fp=fopen("file.txt","r");
		//rewind(fp);
		while(fread(&s, sizeof(struct user), 1, fp)>0)
			{
				//printf("%s\n",s.emailid);
				//fscanf("%d %s %d %l %s %s %s %s %d %s %s %f",&s.id,s.name,&s.age,&s.phno,s.emailid,s.colname,s.regno,s.branch,&s.sem,s.pw,s.lan,&s.cgpa);
				if(strcmp(email,s.emailid)==0)
					{
						fclose(fp);
						printf("Enter a Valid Email ID\n");
						return 0;
					}
			}
		return 1;
	}
int checkphno(char ph[50])
	{
		int i;
		for(i=0;i<strlen(ph);i++)
			{
				if(!(ph[i]>=48 && ph[i]<=57))
					{
						printf("Phone number should consist 10 digit only\n");
						return 0;
					}
			}
		if(strlen(ph)!=10)
			{
				printf("Phone number should consist 10 digit only\n");
				return 0;
			}
		return 1;
	}
int checkcolname(char name[50])
	{
		if(name[0]==' ')
			{
				printf("College name can't be empty! Re-enter College Name\n");
				return 0;
			}
	}
int checkbranch(char branch[50])
	{
		if(strcmp(branch,"Computer Science")==0 || strcmp(branch,"Information Science")==0 || strcmp(branch,"Electronics and communication")==0 || strcmp(branch,"Electrical")==0 || strcmp(branch,"Electronics and Instrumentation")==0)
			{
				return 1;
			}
		printf("Entered branch doesn't belong to list\n");
		return 0;
	}
int checkpw(char pw[50])
	{
		int count=0,count2=0,count3=0,count4=0;
		int i;
		for(i=0;i<strlen(pw);i++)
			{
				if(pw[i]>=65 && pw[i]<=90)
					{
						count++;
					}
				else if(pw[i]>=97 && pw[i]<=122)
					{
						count2++;
					}
				else if(pw[i]>=48 && pw[i]<=57)
					{
						count3++;
					}
				else
					{
						count4++;
					}
			}
		if(count>=2 && count2>=2 && count3>=2 && count4>=2)
			{
				return 1;
			}
		else
			{
				printf("Password must consists of at least 2[A-Z], 2[a-z], 2[!@..+*] and 2[0-9] character\n");
				return 0;
			}
	}
int checkregno(char reg[50])
	{
		if(reg[0]=='4' && reg[1]=='N' && reg[2]=='I')
			return 1;
		else if(reg[0]=='0' && reg[1]=='1' && reg[2]=='J' && reg[3]=='S' && reg[4]=='T')
			return 1;
		else if(reg[0]=='4' && reg[1]=='M' && reg[2]=='H')
			return 1;
		else if(reg[0]=='4' && reg[1]=='V' && reg[2]=='V')
			return 1;
		else if(reg[0]=='4' && reg[1]=='G' && reg[2]=='S')
			return 1;
		else
			printf("Entered registration number doesn't belog to list\n");
			return 0;
	}
int checksem(char sem[50])
	{
		if(!(sem[0]>=49 && sem[0]<=56))
		{
			printf("Semester should be less than 8");
			return 0;
		}
		return 1;
	}
int checkcgpa(char a[50])
	{
		if(a[0]=='1' && a[1]=='0' && a[2]=='.')
			return 1;
		if((a[0]>=49 && a[0]<=57))
			{
			//	printf("a");
				if(a[1]=='.')
					{
						//printf("b");
						if(a[2]>=49 && a[2]<=57)
							{
								return 1;
							}
					}
			}
			printf("\nEnter a valid CGPA\n");
		return 0;
	}
void assign()
{
	struct intern s;
	char ch[50];
	int i=1;
FILE *fp;
fp=fopen("internshipdetails.txt","r");
while(fread(&s,sizeof(struct intern),1,fp)>0)
{

      printf("%d-%s\n",i, s.name);
      i++;
  }
 fclose(fp);
}

void allott(int l,int userid)
{
	FILE *fp;
	int q=l*100;
	printf("arr=%d\n",l);
	int flag=0;
	struct userintdomain a;
	fp=fopen("userintern.txt","r");
	while(fread(&a,sizeof(struct userintdomain),1,fp))
		{
			if(userid==a.uid)
				{
					printf("You have already signed another internship. Complete that first.\n");
					flag=1;
				}
		}
	//q=q+we;
	fclose(fp);
	int count=0;
	////////////////////////////////////////////////
	fp=fopen("userintern.txt","r");
	while(fread(&a,sizeof(struct userintdomain),1,fp))
		{
			if(a.id==l)
				{
					count++;
				}
		}
	//printf("%d\n",count);
	q=q+count;
	///////////////////////////
	if(flag==0)
	{
	//q=rand();
	fp=fopen("userintern.txt","a");
	a.id=l;
	a.uid=userid;
	a.internid=q;
	a.next=NULL;	strcpy(a.batch,"-");
	fwrite(&a,sizeof(struct userintdomain),1,fp);
	//printf("%d has been successfully allotted to you!.",a.id);
	fclose(fp);
	//read();
	}
}
int find()
	{
		FILE *fp;
		struct intern s;
		int count=0;
		fp=fopen("internshipdetails.txt","r");
		while(fread(&s,sizeof(struct intern),1,fp)>0)
			count++;
		fclose(fp);
		return count;
	}
/*void branch(int i)
	{
		struct intern s;
		struct user s2;
		FILE *fp;
		int intake;
		char branch[50];
		fp=fopen("internshipdetails.txt","r");
		while(fread(&s,sizeof(struct intern),1,fp))
			{
				if(i==s.id)
					{
					intake=s.stud;
					strcpy(branch,s.branch);
					}
			}
		fclose(fp);
		
		
	}*/
	int read()
{
	FILE *fp;
	struct userintdomain q;
	int count=0;
	fp=fopen("userintern.txt","r");
	while(fread(&q,sizeof(struct userintdomain),1,fp))
	{
		count++;
	}
	fclose(fp);
	return count;
	
}

int fif(int j)
{
	int i;
	struct userintdomain q;
	struct intern z;
	int bno;
	FILE *fp,*fp1;
		fp1=fopen("internshipdetails.txt","r");
	while(fread(&z,sizeof(struct intern),1,fp1))
	{
		if(j==z.id)
		{
		bno=z.stud;
	//	printf("%d\n",bno);
	//	system("pause");
		break;
	}
	}
	fclose(fp1);
	fp=fopen("userintern.txt","r");
	int size=read();
	struct userintdomain *arr;
	arr=(struct userintdomain *)malloc(size*sizeof(struct userintdomain));
	i=0;
	while(fread(&q,sizeof(struct userintdomain),1,fp))
	{
		arr[i]=q;
		//printf("%s %d",arr[i].batch,i);
		i++;
		
	}
	//system("pause");
fclose(fp);
fp=fopen("userintern.txt","r");
int az1=0;
i=0;
while(fread(&q,sizeof(struct userintdomain),1,fp))
{
	if(arr[i].id==j)
	{
		az1++;
	}
	i++;
}
printf("%d\n",az1);
fclose(fp);

int nob=az1/bno;
int lefto=az1%bno;
int p=az1-lefto;
int k=0;
int t=0;
int op=0;
printf("nob=%d az1=%d bno=%d\n",nob,az1,bno);
printf("j=%d\n",j);
	for(i=0;i<size;i++)
		{
			if(arr[i].id==j)
						{
							arr[i].batch[0]=64+j;
							arr[i].batch[1]=49+t;
							arr[i].batch[2]='\0';
							op++;
						}
					if(op>=bno)
						{
							t++;
						}
					op=op%bno;
		}
	system("pause");
	/*for(k=p;k<az1;k++)
	{
		arr[k].batch[0]=64+j;
		arr[k].batch[1]=49+i;
		arr[k].batch[2]='\0';
	}*/
	fp=fopen("userintern.txt","w");
	i=0;
	for(i=0;i<size;i++)
	{
			fwrite(&arr[i],sizeof(struct userintdomain),1,fp);
	}
	fclose(fp);
}

void critsem()
{
	FILE *fp;
	fp=fopen("user.txt","r");
	struct user s;
	while(fread(&s,sizeof(struct user),1,fp)>0)
		{
			struct user *NN;
		}							
}













