//This is main test file
//Default Admin User Id: 1001
//Default Admin Password: abcd1234
//All information can be found in default_admin() in admin_fun.c file
#include "Bank_fun.h"

int main()
{
	default_admin(); //this will set the default information of admin
	int c,op,account_no,user_id;
	char pass[11],choice;
	do
	{
		printf("Press 1: User Login\n");
		printf("Press 2: Admin Login\n");
		printf("Press 3: EXIT\n");
		scanf("%d",&c);

		switch(c)
		{
			case 1:
				op=Login_Screen();
				if(op==1)
				{
					printf("Enter your Account No: ");
					scanf("%d",&account_no);
					printf("Enter Password: ");
					scanf("%s",pass);
					if(account_no=User_Login(account_no,pass))
						User_Screen(account_no);
					else
					{

						printf("Do you want to Try Again: (Press Y or N): ");
						__fpurge(stdin); //this will flush the buffer
						scanf("%c",&choice);
						if(choice=='Y' || choice=='y')
							continue;
					}
				}
				else if(op==2)
				{
					printf("Enter your Account No: ");
					scanf("%d",&account_no);
					Forgot_Pass_User(account_no);
				}
				break;
			case 2:
				op=Login_Screen();
				if(op==1)
				{
					printf("Enter User ID: \n");
					scanf("%d",&user_id);
					printf("Enter Password: ");
					scanf("%s",pass);
					if(Admin_Login(user_id,pass))
						Admin_Screen();
					//	printf("Admin Screen\n");
					else
					{
						printf("Account Number and Password is not matched\n");
						printf("Do you want to Try Again: (Press Y or N): ");
						__fpurge(stdin); //this will flush the buffer
						scanf("%c",&choice);
						if(choice=='Y' || choice=='y')
							continue;
						else
							return 0;
					}

				}
				else if (op==2)
				{
					printf("Enter your User ID: ");
					scanf("%d",&user_id);
					Forgot_Pass_Admin(user_id);
				}
				break;
			case 3:
				return 0;

			default:
				printf("Invalid Input\n");
				break;
		}
	}while(c!=3);

	return 0;
}
