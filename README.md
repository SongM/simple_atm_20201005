# simple_atm_20201005

code interview question

description:
Implement a simple ATM controller
Write code for a simple ATM. It doesn't need any UI (either graphical or console), but a controller should be implemented and tested.

Requirements
At least the following flow should be implemented:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.

How to submit
Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository.

explanation:
init 10 users, each contains 3 accounts.
user id number: 10001009
pin number: 101000101009
account1 balance: 090;
account2 balance: 0900;
account3 balance: 0~9000;

by running the program,

input user id number, if correct move to step 2, otherwise, move to step 1
input pin number, if correct move to step 3, otherwise, move to step 1
input account number, if input within (1~3), move to step 4, otherwise move to step 1
input operation index (1: see balance, 2, withdraw, 3, deposit),
4.1 if op_ind==1, show balance of the selected account, then go back to step 1
4.2 if op_ind==2 or 3, input withdraw/deposit amount, the amount will be removed(**)/added to the selected account, then go back to step 1.
** for simplicity, the withdraw amount could be greater than the current balance, in other words, the balance could be negative.


**********************************
Due to the lack of knowledge on testing, the testing part of this problem has not addressed. Though there are resources online, the task seems impossible to finish within a short time period. Learning regarding testing will be conducted and the testing part might be updated in the future.
