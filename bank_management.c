#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

int global_temp=-1;	//�ӽ� ��������
int cnt = 0;	// ������ ���� ����
char name[50][50];	//�̸�
int birth[50];		//�������
char pers_num[50][50];	//�ֹε�Ϲ�ȣ
char address[50][50];	//�ּ�
char phone[50][50];	//��ȭ��ȣ
int acnt_pw[50];	//���� ��й�ȣ
long long money[50];	//���� �ܰ�
long long money_loan[50];	//���⳻��

int new_account(void)	// 1. ���� ���� �Լ�
{
	console();
	int choice_acnt;
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\tWould you like to create an account?\n");
	printf("\n\n\n");
	printf("\t\t\t\t1. Saving accont\n");
	printf("\t\t\t\t2. Go back");
	printf("\n\n");

input:
	printf("\t\t\t\tEnter your choice: ");
	scanf_s("%d", &choice_acnt);
	switch (choice_acnt) {
	case 1:
		Saving_acnt();		//���»��� �Լ��� �̵�
		break;
	case 2:
		main();
		break;
	default:
		printf("Error\n\n");
		goto input;
	}
	return 0;
}


int Saving_acnt()	//1_1. ���ݰ��� ���� �Լ�
{
	console();	// �ܼ�â ������Ʈ �� ���󺯰�
	printf("\n\n\n\n");
	printf("\t\t\t\t1. Name: ");	//�̸� �Է�
	while ((getchar() != '\n'));	//���๮�� �����ϰ� fgets����
	fgets(name[cnt], 50, stdin);	//name[cnt][]�� �Է°� �Է�
	printf("\t\t\t\t%s\n", name[cnt]);	//�Է°�(name[cnt] ���)

	printf("\t\t\t\t2. Birthday[YYMMDD]: ");	//������� �Է�
	scanf_s("%d", &birth[cnt]);
	printf("\t\t\t\t%06d\n\n", birth[cnt]);

	printf("\t\t\t\t3. Personal Number[0000000000000]: ");	//�ֹε�Ϲ�ȣ �Է�, ������ ������ �ʹ� Ŀ�� �Է°��� ���ڿ��� ����
	while (getchar() != '\n');
	fgets(pers_num[cnt], 50, stdin);
	//scanf_s("%d", &pers_num[cnt]);	//������ �޾��� ��
	printf("\t\t\t\t%013s\n\n", pers_num[cnt]);

	printf("\t\t\t\t4. Address: ");	//�ּ� �Է�
	fgets(address[cnt], 50, stdin);
	printf("\t\t\t\t%s\n", address[cnt]);

	printf("\t\t\t\t5. Phone Number: ");	//��ȭ��ȣ �Է�, ������ ������ �ʹ� Ŀ�� �Է°��� ���ڿ��� ����
	fgets(phone[cnt], 50, stdin);
	//scanf_s("%s", &phone[cnt]);
	printf("\t\t\t\t%011s\n\n", phone[cnt]);

	printf("\t\t\t\t6. Account Password[000000]: ");	//���� ��й�ȣ ����
	scanf_s("%d", &acnt_pw[cnt]);
	printf("\t\t\t\t%06d\n\n", acnt_pw[cnt]);

	money[cnt] = 0;	//���� �ܰ� 0���� ����
	money_loan[cnt] = 0; //���� ���� 0���� ����
	cnt += 1;
	//Sleep(2000);

	console();
	printf("\n\n\n\n\n");
	printf("\t\t\t\tYour account has been created!!");
	//Sleep(2000);
	new_account();

	return 0;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int update_user(void)	//2. ���� ������Ʈ �Լ�
{
	char edit_answer;
	char again_answer;
	char name_input[50];
	int i;
	int compare;
	int temp=1;
	
	console();
	printf("\n\n\n");
	printf("\t\t\tPlease write the name if you want to update account info.");
	printf("\n\n\n\n");
	printf("\t\t\t\tName: ");

	while ((getchar()) != '\n');
	fgets(name_input, 50, stdin);

	for (i = 0; i < cnt; i++) {		// name�� ����ִ� ���ڿ� ���հ� �Է� ���� ���ڿ� �� ��ġ�ϴ� ���� �ִ��� Ȯ�� �� ��ġ�ϴ� name���ڿ��� ����� ��ȣ ����
		compare = strcmp(name[i], name_input);	//�ΰ� ���ڿ� ��
		if (compare == 0) {
			temp = 0;
			global_temp = i;
		}
	}
	
	if (cnt == 0) {		
		console();		// ���°� �ִ��� �����ϴ� �Լ�. cnt�� 0 �̸� main()���� ���ư�,
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\tNo Account");
		Sleep(1000);
		return main();
	}
	else {

		console();

		if (temp == 0) {
			printf("\n\n");
			printf("\t\t\t============================================================\n");
			printf("\t\t\t\t\t\t���� ���� ���\n");
			printf("\t\t\t============================================================\n");
			printf("\n\n\n");
			printf("\t\t\t\t\t1. Name: %s\n", name[global_temp]);	//global_temp�� ��������, ���߿� �Ʒ��� �ִ� edit_acnt()�Լ����� �ٽ� ����
			printf("\t\t\t\t\t2. Birthday: %06d\n\n", birth[global_temp]);
			printf("\t\t\t\t\t3. Personal Number: %013s\n", pers_num[global_temp]);
			printf("\t\t\t\t\t4. Address: %s\n", address[global_temp]);
			printf("\t\t\t\t\t5. Phone number: %011s\n", phone[global_temp]);
			printf("\t\t\t\t\t6. Account password: %06d\n", acnt_pw[global_temp]);
			printf("\t\t\t\t\t7. Bankbook balance: %d", money[global_temp]);
			if(money_loan[global_temp] != 0) {
				printf("\n\t\t\t\t\t8. Loan: %d\n", money_loan[global_temp]);
			}
			printf("\n\n\n");
			printf("\t\t\t\tWould you like to edit information?[y/n]: ");

			scanf("%c", &edit_answer);
			if (edit_answer == 'y') {
				edit_acnt();//���� �����ϴ� �Լ� ��������
			}
			else {
				return main();	//���� ������ ���ϸ� ����ȭ������ ���ư���
			}
		}
		else {
			printf("\n\n\n");
			printf("\t\t\t\tThis account does not exist.\n");
			printf("\t\t\t\tPlease check again\n");
			printf("\n\n\n\n\n");
			again:
			printf("\t\t\t\tWould you like to try again?[y/n}: ");
			scanf("%c", &again_answer);
			if (again_answer == 'y') {
				update_user();
			}
			else if (again_answer == 'n') {
				main();
			}
			else {
				printf("\n\t\t\t\tError");
				goto again;
			}
		}
	}
	return 0;
}

int edit_acnt()	//2_1. ���� ���� �Լ� 
{
	console();
	char edit_address[50];

	printf("\n\n\n\n");
	printf("\t\t\t\tYour address: %s", address[global_temp]);
	printf("\t\t\t\tEdit: ");
	
	while (getchar() != '\n');
	fgets(edit_address, 50, stdin);
	strcpy_s(address[global_temp], 50, edit_address);
	
	printf("\n\n\n");
	printf("\t\t\t\tYour phone number: %s", phone[global_temp]);
	printf("\t\t\t\tEdit: ");

	fgets(edit_address, 50, stdin);
	strcpy_s(phone[global_temp], 50, edit_address);
	

	printf("\n\n\n\n");
	printf("\t\t\t\tYour modifications have been saved!!");
	global_temp = -1;
	Sleep(2000);
	main();
	return 0;
}

int translate()	//3. ���- ���� ���� ��� ����
{
	int method;
	console();
	goto jump;
	input:
	printf("\t\t\t\tError");
	jump:
	printf("\n\n\n\n");
	printf("\t\t\t\t\tAccount Selection\n");
	printf("\t\t\t\tPlease select a method\n");
	printf("\n\n\n");
	printf("\t\t\t\t1. Enter your name\n");
	printf("\t\t\t\t2. Choose from account list\n");
	printf("\n\n\n\t\t\t\t");
	printf("Enter your choice: ");
	scanf_s("%d", &method);
	if (method == 1) {
		input_name();
	}
	else if (method == 2) {
		user_list();
	}
	else {
		goto input;
	}
	return 0;
}

int input_name(void)	//3_1. ���� ȣ�� ��� �� �̸� �Է��ϴ� �Լ�
{
	int work_choice;
	char again_answer;
	char name_input[50];
	int i;
	int compare;
	int temp = 1;

	console();
	printf("\n\n\n");
	printf("\t\t  Please enter your name if you want to work with your account.");
	printf("\n\n\n\n");
	printf("\t\t\t\tName: ");

	while ((getchar()) != '\n');
	fgets(name_input, 50, stdin);

	for (i = 0; i < cnt; i++) {		// name�� ����ִ� ���ڿ� ���հ� �Է� ���� ���ڿ� �� ��ġ�ϴ� ���� �ִ��� Ȯ�� �� ��ġ�ϴ� name���ڿ��� ����� ��ȣ ����
		compare = strcmp(name[i], name_input);	//�ΰ� ���ڿ� ��
		if (compare == 0) {
			temp = 0;
			global_temp = i;
		}
	}

	if (cnt == 0) {
		console();		// ���°� �ִ��� �����ϴ� �Լ�. cnt�� 0 �̸� main()���� ���ư�,
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\tNo Account");
		Sleep(1000);
		return main();
	}
	else {
		if (temp == 0) {
			goto jump;
			choice_again:
			console();
			printf("\n\n\n");
			printf("\t\t\t\t\t Error");
			jump:
			console();
			printf("\n\n\n\n");
			printf("\t\t\t\t\tWelcome %s\n", name[global_temp]);
			printf("\t\t\t\t1. Withdraw\n\n");
			printf("\t\t\t\t2. Deposit\n\n");
			printf("\t\t\t\t3. Exit\n\n");
			printf("\t\t\t\tChoose what to do: ");

			scanf_s("%d", &work_choice);
			if (work_choice == 1) {
				withdraw();
			}
			else if(work_choice == 2) {
				deposit();//�����ϴ� �Լ� �������� // �Լ� ��� �� �������� global_temp�� -1�� �ʱ�ȭ
			}
			else if (work_choice == 3) {
				main();
			}
			else {
				goto choice_again;
			}
		}
		else {
			printf("\n\n\n");
			printf("\t\t\t\tThis account does not exist\n");
			printf("\t\t\t\tPlease check again\n");
			printf("\n\n\n\n\n");
		again:
			printf("\t\t\t\tWould you like to try again?[y/n}: ");
			scanf_s("%c", &again_answer);
			if (again_answer == 'y') {
				input_name();
			}
			else if (again_answer == 'n') {
				main();
			}
			else {
				printf("\n\t\t\t\tError");
				goto again;
			}
		}
	}
	return 0;
}

int user_list()		//3_2. ���� ȣ�� ��� �� ����Ʈ ����
{
	int work_choice;
	int temp;
	goto jump_1;
	int i;
	again:
	printf("\n\n\t\t\t\tError. Enter again");
	jump_1:
	console();
	printf("\n\n\n");
	printf("\t\t\t\tAccount List");
	printf("\n\n\n\n\n");

	for (i = 0; i < cnt; i++) {	//�̸�, �ֹι�ȣ, �ּ�, ��ȭ��ȣ
		printf("\t\t\t\t%d. name: ", (i + 1)); printf("%s", name[i]);
		printf("\t\t\t\t  personal_num: %s", pers_num[i]);
		printf("\t\t\t\t  phone_num: %s\n", phone[i]);
		printf("\t\t\t\t  Money: %d\n", money[i]);
		if(money_loan[i] !=0) {
			printf("\t\t\t\t  Loan: %d", money_loan[i]);
		}
	}
	printf("\t\t\t\t%d. Exit: ", cnt+1);
	printf("\n\n\n");
	printf("\t\t\t\tChoose the number to edit: ");
	scanf("%d", &temp);
	global_temp = temp - 1;
	if (global_temp < -1) {
		goto again;
	}
	else if (global_temp > cnt) {
		goto again;
	}
	else if (global_temp == cnt) {
		main();
	}
	else {
		goto jump_2;
		choice_again:
		printf("\n\n\t\t\t\tError. Enter again");
		jump_2:
		console();
		printf("\n\n\n\n");
		printf("\t\t\t\t\tWelcome %s\n", name[global_temp]);
		printf("\t\t\t\t1. Withdraw\n\n");
		printf("\t\t\t\t2. Deposit\n\n");
		printf("\t\t\t\t3. go back\n\n");
		printf("\t\t\t\tChoose what to do: ");

		scanf_s("%d", &work_choice);
		if (work_choice == 1) {
			withdraw();		//����ϴ� �Լ� ��������
		}
		else if (work_choice == 2) {
			deposit();		//�����ϴ� �Լ� �������� // �Լ� ��� �� �������� global_temp�� -1�� �ʱ�ȭ
		}
		else if (work_choice == 3) {
			user_list();
		}
		else {
			goto choice_again;
		}
	}
	return 0;
}

int withdraw()		//���� ����, ��� ����
{
	long long input_money = 0;
	int yes_no_;
	int more_work;
	goto jump;
	again:
	printf("\n\n\t\t\t\tEnter again");
	jump:
	console();
	printf("\n\n\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\t\tMoney Withdrawal\n");
	printf("\t\t\t============================================================\n");
	printf("\n\n");
	printf("\t\t\t\tMoney: %d\n", money[global_temp]);
	printf("\t\t\t\tEnter the amount to withdraw\n");
	printf("\t\t\t\t->");
	scanf_s("%d", &input_money);
	if (input_money >= 0) {
		if ((money[global_temp] - input_money) < 0) {		//�Է��� ���� �ܰ��� ���� ��
			printf("\n\n\n\n\t\t\t\t\tNot enough money\n");
			printf("\n\t\t\t\tYour bankbook balance: %d\n", money[global_temp]);
			if(money_loan[global_temp] != 0) {
				printf("\t\t\t\tLoan: %d\n", money_loan[global_temp]);
			}
			printf("\t\t\t\tWould you like to enter it again? \n\n\n");
			printf("\t\t\t\t1. YES \n\n");
			printf("\t\t\t\t2. NO \n\n\n");
			printf("\t\t\t\tChoose it: ");
			scanf("%d", &yes_no_);
			if (yes_no_ == 1) {
				goto again;
			}
			else if (yes_no_ == 2) {
				global_temp = -1;
				main();
			}
			else {
				goto again;
			}
		}
		else {	// �Է��� ���� ����� �� ������ŭ ���� ��
			console();
			money[global_temp] -= input_money;
			printf("\n\n\n\n");
			printf("\t\t\t\t\t%dwon was withdrawn!!\n", input_money);
			printf("\t\t\t\t\tbankbook balance: %d\n\n", money[global_temp]);
			if(money_loan[global_temp] != 0) {
				printf("\t\t\t\tLoan: %d\n\n", money_loan[global_temp]);
			}
			choice:
			printf("\n\t\t\t\t  Do you want to do anything else?\n\n");
			printf("\t\t\t\t1. withdraw\n");
			printf("\t\t\t\t2. deposit\n");
			printf("\t\t\t\t3. another account\n");
			printf("\t\t\t\t4. Exit\n");
			printf("\t\t\t\t->");
			scanf("%d", &more_work);
			if (more_work == 1) {
				withdraw();
			}
			else if (more_work == 2) {
				deposit();
			}
			else if (more_work == 3) {
				translate();
			}
			else {
				main();
			}
		}
	}
	else {
		goto again;
	}
	return 0;
}

int deposit()	//3_0_2. ���� �Լ�
{
	long long input_money=0;
	int more_work;
	goto jump;
again:
	printf("\n\n\t\t\t\tEnter again");
	jump:
	console();
	printf("\n\n\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\t\tMoney deposit\n");
	printf("\t\t\t============================================================\n");
	printf("\n\n");
	printf("\t\t\t\tMoney: %d\n", money[global_temp]);
	if(money_loan[global_temp] != 0) {
		printf("\t\t\t\tLoan: %d\n", money_loan[global_temp]);
	}
	printf("\t\t\t\tEnter the amount to deposit\n");
	printf("\t\t\t\t->");
	scanf_s("%d", &input_money);

	if (input_money >= 0) {
		money[global_temp] += input_money;		// �Է��� �ݾ��� ����̸� �ܱ� ���� ������Ʈ
		console();
		printf("\n\n\n\n");
		printf("\t\t\t\t%d won was deposited!!\n", input_money);
		printf("\t\t\t\tBankbook balance: %d\n\n", money[global_temp]);
		if(money_loan[global_temp] != 0) {
			printf("\t\t\t\tLoan: %d\n\n", money_loan[global_temp]);
		}
		printf("\n\t\t\t\tDo you want to do anything else?\n\n");
		printf("\t\t\t\t1. withdraw\n");
		printf("\t\t\t\t2. deposit\n");
		printf("\t\t\t\t3. another account\n");
		printf("\t\t\t\t4. Exit\n");
		printf("\t\t\t\t->");
		scanf("%d", &more_work);
		if (more_work == 1) {
			withdraw();
		}
		else if (more_work == 2) {
			deposit();
		}
		else if (more_work == 3) {
			translate();
		}
		else {
			main();
		}
	}
	else {
		goto again;
	}
	return 0;
}

int account_detail()	//4. ���� ���� Ȯ�� �Լ�
{
	int choice_num=0;
	int temp;
	int i;
	char yes_no;

	console();
	goto jump_1;
again_1:
	printf("\n\n\t\t\t\tError. Enter again");
jump_1:
	console();
	printf("\n\n\n");
	printf("\t\t\t\tAccount List");
	printf("\n\n\n\n\n");

	for (i = 0; i < cnt; i++) {	//�̸�, �ֹι�ȣ, �ּ�, ��ȭ��ȣ
		printf("\t\t\t\t%d. name: ", (i + 1)); printf("%s", name[i]);
		printf("\t\t\t\t   personal_num: %s", pers_num[i]);
		printf("\t\t\t\t   phone_num: %s", phone[i]);
		printf("\t\t\t\t   Bankbook balance: %d\n\n", money[i]);
		if(money_loan[i] != 0) {
			printf("\t\t\t\t  Loan: %d\n\n", money_loan[i]);
		}
	}
	printf("\t\t\t\t%d. Exit: ", cnt + 1);
	printf("\n\n\n");
	printf("\t\t\t\tChoose the number to edit: ");
	scanf("%d", &choice_num);
	if (choice_num < 0) {
		goto again_1;
	}
	else if (choice_num > cnt + 1) {
		goto again_1;
	}
	else if (choice_num == cnt + 1) {
		main();
	}
	else {
		temp = choice_num - 1;
		again_2:
		console();
		printf("\n\n");
		printf("\t\t\t============================================================\n");
		printf("\t\t\t\t\t\t���� ���� ���\n");
		printf("\t\t\t============================================================\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t1. Name: %s\n", name[temp]);
		printf("\t\t\t\t\t2. Birthday: %06d\n\n", birth[temp]);
		printf("\t\t\t\t\t3. Personal Number: %013s\n", pers_num[temp]);
		printf("\t\t\t\t\t4. Address: %s\n", address[temp]);
		printf("\t\t\t\t\t5. Phone number: %011s\n", phone[temp]);
		printf("\t\t\t\t\t6. Account password: %06d\n", acnt_pw[temp]);
		printf("\t\t\t\t\t7. Bankbook balance: %d", money[temp]);
		if(money_loan[temp] != 0) {
			printf("\t\t\t\t\t8. Loan: %d\n", money_loan[temp]);
		}
		printf("\n\n\n");
		printf("\t\t\t\tWould you like to check another account?[y/n]: ");

		scanf("%c", &yes_no);
		if (yes_no == 'y') {
			account_detail();
		}
		else if (yes_no == 'n') {
			main();
		}
		else {
			goto again_2;
		}
	}
	return 0;
}

int erase_home()		// ���� ���� �Լ�  
{
	int i;
	int acnt_delete;
	int yes_no;
	goto jump;
again:
	printf("\n\n\t\t\t\tEnter again");
jump:
	console();
	printf("\n\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\tRemove Account\n");
	printf("\t\t\t============================================================\n");
	printf("\n\n");	
	
	for (i = 0; i < cnt; i++) {	//�̸�, �ֹι�ȣ, �ּ�, ��ȭ��ȣ
		printf("\t\t\t\t%d. name: ", (i + 1)); printf("%s", name[i]);
		printf("\t\t\t\t   personal_num: %s", pers_num[i]);
		printf("\t\t\t\t   phone_num: %s\n", phone[i]);
		printf("\t\t\t\t   Bankbook balance: %d\n", money[i]); 
		if(money_loan[i] != 0) {
			printf("\t\t\t\t  Loan: %d\n", money_loan[i]);
		}
	}
	printf("\t\t\t\t%d. Exit\n\n", cnt+1);
	printf("\n\n\n");
	printf("\t\t\t\tChoose an account to delete: ");
	scanf("%d", &acnt_delete);
	if(acnt_delete <= 0) {
		goto again;
	}
	else if(acnt_delete >cnt+1) {
		goto again;
	}
	else if(acnt_delete ==cnt+1) {
		main();
	}
	else {
		global_temp = acnt_delete - 1;
		goto jump_2;
		again_2:
			printf("\n\t\t\t\tEnter again");
		jump_2:
		console();
		printf("\n\n");
		printf("\t\t\t============================================================\n");
		printf("\t\t\t\t\t\t���� ���� ���\n");
		printf("\t\t\t============================================================\n");
		printf("\n\n\n");
		printf("\t\t\t\t\t1. Name: %s\n", name[global_temp]);
		printf("\t\t\t\t\t2. Birthday: %06d\n\n", birth[global_temp]);
		printf("\t\t\t\t\t3. Personal Number: %013s\n", pers_num[global_temp]);
		printf("\t\t\t\t\t4. Address: %s\n", address[global_temp]);
		printf("\t\t\t\t\t5. Phone number: %011s\n", phone[global_temp]);
		printf("\t\t\t\t\t6. Account password: %06d\n", acnt_pw[global_temp]);
		printf("\t\t\t\t\t7. Bankbook balance: %d", money[global_temp]);
		if(money_loan[global_temp] != 0) {
			printf("\t\t\t\t\t8. Loan: %d\n", money_loan[global_temp]);
		}
		printf("\n\n\n");
		printf("\t\t\t\tAre you sure you want to delete your account?");
		printf("\n\t\t\t\t1. YES");
		printf("\n\t\t\t\t2. NO");

		scanf("%d", &yes_no);
		if (yes_no == 1) {
			account_delete();
		}
		else if (yes_no == 2) {
			main();
		}
		else {
			goto again_2;
		}
	}
	return 0;
}

int account_delete() //�̸�, �������, �ֹε����ȣ, �ּ�, ��ȭ��ȣ, �������, ��, ���� 
{
	console();
	int temp;
	char temp_str[50];
	int i;
	
	for(i=global_temp; i<cnt; i++) {
		if(i == cnt-1) {
			cnt -= 1;
			break;
		}
		strcpy(name[i], name[i+1]);
		strcpy(pers_num[i], pers_num[i+1]);
		strcpy(address[i], address[i+1]);
		strcpy(phone[i], phone[i+1]);
		birth[i] = birth[i+1];
		acnt_pw[i] = acnt_pw[i+1];
		money[i] = money[i+1];
		money_loan[i] = money_loan[i+1];
	}
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\tYour account has been deleted!!");
	Sleep(1000);
	return 0;
}

int loan_money_home()	//6�� �̽��Ϳ���. ���� ���
{
	console();
	int work_choice;
	int i, j;
	int local_cnt=0;
	goto jump;
again:
	printf("\n\n\t\t\t\tEnter again");
jump:
	console();
	printf("\n\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\t\tMoney Loan\n");
	printf("\t\t\t============================================================\n");
	printf("\n\n");	


	for (i = 0; i < cnt; i++) {
		if (money_loan[i] != 0) {
			printf("\t\t\t\t%d. name: ", (i + 1)); printf("%s", name[i]);
			printf("\t\t\t\t  personal_num: %s", pers_num[i]);
			printf("\t\t\t\t  phone_num: %s", phone[i]);
			printf("\t\t\t\t  Bankbook balance: %d", money[i]);
			printf("\t\t\t\t  Loan history: %d\n\n", money_loan[i]);
			local_cnt += 1;
		}
	}

	if (local_cnt == 0) {
		printf("\n\n\t\t\t\t\tNone\n");
	}

	printf("\n\t\t\t\tWould you like to borrow it?");
	printf("\n\n\t\t\t\t1. YES \n");
	printf("\t\t\t\t2. NO\n");
	printf("\t\t\t\tChoose it: ");
	scanf("%d", &work_choice);
	if (work_choice == 1) {
		loan_money();
	}
	else if (work_choice == 2) {
		main();
	}
	else {
		goto again;
	}
	return 0;
}

int loan_money()
{
	int choice_num = 0;
	int temp;
	char yes_no;
	long long input_money;
	int i;

	console();
	goto jump_1;
again_1:
	printf("\n\n\t\t\t\tError. Enter again");
jump_1:
	console();
	printf("\n\n\n");
	printf("\t\t\t\tAccount List");
	printf("\n\n\n\n\n");

	for (i = 0; i < cnt; i++) {	//�̸�, �ֹι�ȣ, �ּ�, ��ȭ��ȣ
		printf("\t\t\t\t%d. name: ", (i + 1)); printf("%s", name[i]);
		printf("\t\t\t\t   personal_num: %s", pers_num[i]);
		printf("\t\t\t\t   phone_num: %s\n", phone[i]);
	}
	printf("\t\t\t\t%d. Exit: ", cnt + 1);
	printf("\n\n\n");
	printf("\t\t\t\tChoose the account to loan: ");
	scanf("%d", &choice_num);
	global_temp = choice_num - 1;
	if (global_temp < 0) {
		goto again_1;
	}
	else if (choice_num > cnt + 1) {
		goto again_1;
	}
	else if (choice_num == cnt + 1) {
		main();
	}
	else {		 // ������Ұ��� ������
		goto jump_2;
		again_2:
		printf("\n\n\t\t\t\tEnter again");
		jump_2:
		console();
		printf("\n\n\n");
		printf("\t\t\t============================================================\n");
		printf("\t\t\t\t\t\tMoney Loan\n");
		printf("\t\t\t============================================================\n");
		printf("\n\n");
		printf("\t\t\t\tYour bankbook balance: %d\n", money[global_temp]);
		printf("\t\t\t\tEnter the amount to loan\n");
		printf("\t\t\t\t->");
		scanf_s("%d", &input_money);
		
		money_loan[global_temp] += input_money;
		printf("\n\n\t\t\t\tSuccessful Loan!!");
		Sleep(1000);
		loan_money_home();
	}
	return 0;
}

int console()
{
	system("cls");	//�ܼ�â ������Ʈ
	system("color 70");		//�ܼ�â ����� ����������, �۾��� �Ķ������� ����
	system("mode con: cols=110 lines=30"); //// �ܼ�â ũ�� ���� ���� 5:3���� ����
}

int main(void)
{
	int choice=0;

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");	//�� �ٲ�
	printf("\t\t\t\t  BANKING MANAGEMENT SYSTEM");	
	Sleep(1000);	//printf �Լ� ��� �� 1�� ���

	again:
	console();
	printf("\n\n\n\n\n");
	printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n");
	printf("\t\t\t\t======= WELCOME TO THE MAIN MENU =======\n\n");
	printf("\t\t\t\t1. Create new account\n");
	printf("\t\t\t\t2. Update information of existing account\n");
	printf("\t\t\t\t3. For transactions\n");
	printf("\t\t\t\t4. Check the details of existing account\n");
	printf("\t\t\t\t5. Removing existing account\n");
	printf("\t\t\t\t6. Loan\n");
	printf("\t\t\t\t7. Exit\n");
	
	printf("\n\n\n");
	printf("\t\t\t\tEnter your choice: ");
	scanf_s("%d", &choice);

	if (choice == 1) {
		new_account();
	}
	
	if (cnt == 0) {
		console();		// ���°� �ִ��� �����ϴ� �Լ�. cnt�� 0 �̸� main()���� ���ư�,
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\tNo Account\n");
		printf("\t\t\t\t\t\tCreat account");
		Sleep(1000);
		return main();
	}
	else {
		if (choice == 2) {
			update_user();
		}
		else if (choice == 3) {
			translate();
		}
		else if (choice == 4) {
			account_detail();
		}
		else if (choice == 5) {
			erase_home();
		}
		else if (choice == 6) {
			loan_money_home();
		}
		else if (choice == 7) {
			return 0;
		}
		else {
			goto again;
		}
	}
}
