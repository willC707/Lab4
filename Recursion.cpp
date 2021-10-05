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
		else
		{
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


std::string ChessBoard::Solve(ChessBoard chessBoard) {

	int i = 0;
	int col = 0;

	while (m_Position.size() != 8)
	{
		if (CheckSafeQueens(chessBoard, i, col))
		{
			m_Position.push(chessBoard.m_board);
			chessBoard.m_board[i][col] = 1;
			
			iterator.push(i);
			iterator.push(col);
		}
		else if( i > 7)
		{
			chessBoard = chessBoard.m_Position.top();
			col = iterator.top();
			iterator.pop();
			i = iterator.top();
			iterator.pop();
			chessBoard.m_Position.pop();
			if(col == 7)
			{
				i +=1;
				col =0;
			}
			else{
				col+=1;
			}
		}
		if(col == 7)
		{
			col = 0;
			i+=1;
		}
		else{col +=1;}
	}

	std::string str = ToString(chessBoard.m_Position.top());
	return str;
	//return true;









	/*if (col >= 8) {
		return true;
	}*/
	// array <int, 2> tempPosition;

	// while (!m_boardSolved)
	// {
	// 	//bool badPath = true;
	// 	//cout << "test" << endl;
	// 	for (int i = 0; i <=7; i++){
	// 		for (int j = 0; j <=7; j++){

	// 			tempPosition = {i, j};
				

	// 			if(CheckSafeQueens(chessBoard, tempPosition.end()[0], tempPosition.end()[1]))
	// 			{
	// 				m_Position.push(tempPosition);
	// 				m_board[m_Position.top()[0]][m_Position.top()[1]] = 1;
	// 				if (tempPosition.size() == 8){
	// 					return true;
	// 				}
	// 				break;
	// 			}
	// 			else
	// 			{

	// 				m_Position.pop();
	// 			}
	// 		}
	// 	}

	// }

	/*for (int i = 0; i < 8; ++i) {

		if (CheckSafeQueens(chessBoard, i, col)) {
			m_board[i][col] = 1;


			if (Solve(chessBoard, col + 1) == true)
				return true;

			m_board[i][col] = 0;

		}
	}*/
	//return false;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{

 	for (int i = 0; i < 8; i++) { // same thing as earlier but with columns
		if (chessBoard.m_board[i][col] == 1) { // if the spot has a queen, and no queen has bee found yet, show that is our first queen
			//m_Position.pop();
			return false;
		}
	}
	 
	 for (int i = 0; i < 8; i++) { // same thing as earlier but with columns
		if (chessBoard.m_board[row][i] == 1) { // if the spot has a queen, and no queen has bee found yet, show that is our first queen
			//m_Position.pop();
			return false;
		}
	}

	if (!CheckNorthEast(chessBoard, row, col))
	{
		//m_Position.pop();
		return false;
	}

	else if (!CheckNorthWest(chessBoard, row, col))
	{
		//m_Position.pop();
		return false;
	}

	else if (!CheckSouthEast(chessBoard, row, col))
	{
		//m_Position.pop();
		return false;
	}

	else if (!CheckSouthWest(chessBoard, row, col))
	{
		//m_Position.pop();
		return false;
	}

	else{return true;}

    // TODO
}


	


bool ChessBoard::CheckNorthEast(ChessBoard chessBoard, int row, int col)
{
	int cur_col = col;
	int cur_row = row;
	while (cur_col <= 7 && cur_row >= 0) {
		// check north east
		if (chessBoard.m_board[cur_row][cur_col] == 1) {
			return false;
		}

		// increment column, decrement row
		cur_col++;
		cur_row--;
	}

	return true;
}

bool ChessBoard::CheckNorthWest(ChessBoard chessBoard, int row, int col)
{
	int cur_col = col;
	int cur_row = row;
	while (cur_col >= 0 && cur_row >= 0) {
		// check north west
		if (chessBoard.m_board[cur_row][cur_col] == 1) {
			return false;
		}

		// decrement both variables
		cur_col--;
		cur_row--;
	}

	return true;
}

bool ChessBoard::CheckSouthEast(ChessBoard chessBoard, int row, int col)
{
	int cur_col = col;
	int cur_row = row;
	while (cur_col <= 7 && cur_row <= 7) {
		// check south east
		if (chessBoard.m_board[cur_row][cur_col] == 1) {
			return false;
		}

		// increment both
		cur_col++;
		cur_row++;
	}

	return true;
}

bool ChessBoard::CheckSouthWest(ChessBoard chessBoard, int row, int col)
{
	int cur_col = col;
	int cur_row = row;
	while (cur_col >= 0 && cur_row <= 7) {
		// check south west
		if (chessBoard.m_board[cur_row][cur_col] == 1) {
			return false;
		}

		// decrement column, increment row
		cur_col--;
		cur_row++;
	}

	return true;

}


std::string ChessBoard::ToString(ChessBoard board) {
	
	
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

char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "I got Exception 1";
}
char const* MyException2::what() const throw() {
	return "I got Exception 2";
}
char const* MyException3::what() const throw() {
	return "I got Exception 3";
}

// TODO make a MyException3::what

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

	try
	{
		SimpleExceptionMethod(i);
		retVal = "I did not get an Exception";
	}
	catch(MyException1& e)
	{
		retVal = e.what();
	}
	catch(MyException2& e)
	{
		retVal = e.what();
	}
	catch(MyException3& e)
	{
		retVal = e.what();
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






