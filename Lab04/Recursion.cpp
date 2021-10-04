#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) {

	if (num <= 1)
	{
		return 1;
	}

	else 
	{
		return num * CalculateFactorial(num - 1);  
	}
}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

	if (num <= 1) { return 1; }

	while (num > 1) {
		s.push(num);
		num--;
	}
	while (!s.empty()) {
		answer = answer * s.top();
		s.pop();
	}
	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	if (col >= 8) {
		return true;
	}


	for (int i = 0; i < 8; ++i) {

		if (CheckSafeQueens(chessBoard, i, col)) {
			m_board[i][col] = 1;


			if (Solve(chessBoard, col + 1) == true)
				return true;

			m_board[i][col] = 0;

		}
	}
	return false;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{
	bool conflict = false;
	bool first_queen = false; // two boolean variables used for checks
	for (int i = 0; i < 8; i++) { // check every space in the row
		if (chessBoard.m_board[row][i] == 1 && !first_queen) { // if the spot has a queen, and no queen has been found yet, show that is our first queen
			first_queen = true;
		}
		else if(chessBoard.m_board[row][i] == 1) { // if you find a second queen set the variable and leave loop
			conflict = true;
			break;
		}
	}

	if(conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	first_queen = false; // reset variable
 	for (int i = 0; i < 8; i++) { // same thing as earlier but with columns
		if (chessBoard.m_board[i][col] == 1 && !first_queen) { // if the spot has a queen, and no queen has bee found yet, show that is our first queen
			first_queen = true;
		}
		else if(chessBoard.m_board[i][col] == 1) { // if you find a second queen set the variable and leave loop
			conflict = true;
			break;
		}
	}

	if (conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	first_queen = false; // reset variable
	int cur_col = col;
	int cur_row = row;
	while (cur_col >= 0 && cur_row >= 0) {
		// check north west
		if (chessBoard.m_board[cur_row][cur_col] == 1 && !first_queen) {
			first_queen = true; // show first queen has been found
		}

		else if (chessBoard.m_board[cur_row][cur_col] == 1) {
			conflict = true;
			break;
		}

		// decrement both variables
		cur_col--;
		cur_row--;
	}

	if (conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	first_queen = false; // reset variables
	int cur_col = col;
	int cur_row = row;
	while (cur_col >= 0 && cur_row <= 7) {
		// check south west
		if (chessBoard.m_board[cur_row][cur_col] == 1 && !first_queen) {
			first_queen = true; // show first queen has been found
		}

		else if (chessBoard.m_board[cur_row][cur_col] == 1) {
			conflict = true;
			break;
		}
		// decrement column, increment row
		cur_col--;
		cur_row++;
	}

	if (conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	first_queen = false; // reset variables
	int cur_col = col;
	int cur_row = row;
	while (cur_col <= 7 && cur_row >= 0) {
		// check norht east
		if (chessBoard.m_board[cur_row][cur_col] == 1 && !first_queen) {
			first_queen = true; // show first queen has been found
		}

		else if (chessBoard.m_board[cur_row][cur_col] == 1) {
			conflict = true;
			break;
		}
		// increment column, decrement row
		cur_col++;
		cur_row--;
	}

	if (conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	first_queen = false; // reset variables
	int cur_col = col;
	int cur_row = row;
	while (cur_col <= 7 && cur_row <= 7) {
		// check south east
		if (chessBoard.m_board[cur_row][cur_col] == 1 && !first_queen) {
			first_queen = true; // show first queen has been found
		}

		else if (chessBoard.m_board[cur_row][cur_col] == 1) {
			conflict = true;
			break;
		}
		// increment both
		cur_col++;
		cur_row++;
	}

	if (conflict) {
		return false; // if there was a conflict leave the function and return false
	}

	else {
		return true;
	}
}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal;
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;

	resourceThatNeedsToBeCleanedup = new MyFakeClass();

	try{
		SimpleExceptionMethod(i);
		retVal = "I did not get an Exception";
	}
	catch(MyException1){
		retVal = "I got Exception 1";
	}
	catch(MyException2& e){
		retVal = "I got Exception 2";
	}
	catch(MyException3& e){
		retVal = "I got Exception 3";
	}

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
// TODO make a MyException3::what
char const* MyException3::what() const throw() {
	return "MyException3";
}

//palindromeRecursion::palindromeRecursion() {}

bool palindromeRecursion::palidromeCalculator(string strToCalculate)
{
	
	if(strToCalculate.empty())
	{
		cout << "This string is empty.\n";
		return false;
	}
	while(strToCalculate.size() > 1)
	{
		if(strToCalculate.front() == strToCalculate.back())
		{
			if(strToCalculate.size() > 2)
			{
				strToCalculate = strToCalculate.substr(1,(strToCalculate.size() - 2));
				palidromeCalculator(strToCalculate);
			}
			else{break;}

			
		}
		else{
			return false;
		}
	}
	return true;
}

//palindromeStack::palindromeStack() {}

bool palindromeStack::palidromeCalculator(string strToCalculate)
{
	if(strToCalculate.size() == 0)
	{
		cout<<"This string is empty.\n";
		return false;
	}
	int i =0;
	while(i < strToCalculate.size())
	{
		s.push(strToCalculate[i]);
		i += 1;
	}
	//cout << strToCalculate<< endl;

	for(int i =0; i<strToCalculate.size();i++){
		if(strToCalculate[i] != s.top())
		{
			return false;
		}
		s.pop();
	}
	return true;

}
