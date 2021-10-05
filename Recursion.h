#include <vector>

#include <stack>
#include <array>
#include <string>
#include <iostream>

using namespace std;

class  IFactorialComputer
{
public:
	IFactorialComputer() {};
	virtual int CalculateFactorial(int numberToComputer) = 0;
};


class  FactorialByRecursion : public IFactorialComputer
{
public:
	FactorialByRecursion() {};
	int CalculateFactorial(int num);
};
class  FactorialByStack : public IFactorialComputer
{
public:
	FactorialByStack() {};
	
	int CalculateFactorial(int num);

private:
	std::stack <int> s;
};


class IpalidromeCalculator {
	public:
		IpalidromeCalculator() {};
		virtual bool palidromeCalculator(string strToCalculate) = 0;
};

class palindromeRecursion : public IpalidromeCalculator {
	public:
		palindromeRecursion() {};
		bool palidromeCalculator(string strToCalculate);

	private:

};
class palindromeStack : public IpalidromeCalculator {
	public:
		palindromeStack() {};
		bool palidromeCalculator(string strToCalculate);

	private:
		stack <char> s;

};


class  MyFakeClass
{
public:
	MyFakeClass() {std::cout << "Constructor for MyFakeClass was called" << std::endl;}
	~MyFakeClass() { std::cout << "Destructor for MyFakeClass was called" << std::endl; }

};

class  MyBaseException : public std::exception
{
public:

	virtual char const* what() const throw();
};

class  MyException1 : MyBaseException
{
public:
	
	virtual char const* what() const throw();
};


class  MyException2 : MyBaseException
{
public:
	
	virtual char const* what() const throw();
};

class  MyException3 : MyBaseException
{
public:
	
	virtual char const* what() const throw();
};

// TODO make a MyException3


extern  std::string CallSimpleExceptionMethod(int i);
extern  void SimpleExceptionMethod(int i);


// This class is exported from the RecursionList.dll
class  ChessBoard {
public:
	ChessBoard() 
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				m_board[i][j] = 0;
			}
		}
		m_boardSolved = false;
	}

	ChessBoard(int board[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				m_board[i][j] = board[i][j];
			}
		}
		m_boardSolved = false;
	}

	std::string ToString(ChessBoard board);
	
	std::string Solve(ChessBoard chessboard);
	

private:
    bool CheckSafeQueens(ChessBoard chessBoard, int i, int col);
	int m_board[8][8]; //zero is free, while 1 is a placed queen
	stack <int [8][8]> m_Position; // TODO: add your methods here.
	stack <int> iterator;
	bool m_boardSolved;
	bool CheckNorthEast(ChessBoard chessBoard, int row, int col);
	bool CheckNorthWest(ChessBoard chessBoard, int row, int col);
	bool CheckSouthEast(ChessBoard chessBoard, int row, int col);
	bool CheckSouthWest(ChessBoard chessBoard, int row, int col);

};


