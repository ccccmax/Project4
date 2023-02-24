#include "matrix.h"
#include<fstream>


Matrix::Matrix():cols(0),rows(0),data(vector<vector<float>>(0,vector<float>(0))){}

Matrix::Matrix(int cols, int rows):cols(cols),rows(rows),data(vector<vector<float>>(rows,vector<float>(cols))){}

Matrix::Matrix(int cols, int rows, const vector<vector<float>>& data):cols(cols),rows(rows),data(data){}

Matrix Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->data = other.data;
	}
	return *this;
}

Matrix operator*(const Matrix& A,const  Matrix& B)
{
	if (A.cols != B.rows)
	{
		cout << "两矩阵不能相乘" << endl
			<< "A矩阵为" << A.cols << '*' << A.rows << endl
			<< "B矩阵为" << B.cols << '*' << B.rows << endl;
		return Matrix();
	}
	
	Matrix result(A.rows, B.cols);
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < B.cols; j++) {
			float sum = 0;
			for (int k = 0; k < A.cols; k++) {
				sum += A.data[i][k] * B.data[k][j];
			}
			result.data[i][j] = sum;
		}
	}
		return result;
}

Matrix operator*(const Matrix& A, float b)
{
	Matrix result(A.cols, A.rows);

	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			result.data[i][j] = A.data[i][j] * b;
		}
	}

	return result;
}

Matrix operator*(float a, const Matrix& B)
{
	return B*a;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
			os << m.data[i][j]<<' ';
		os << endl;
	}
		return os;
}


