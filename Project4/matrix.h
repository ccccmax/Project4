#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
class Matrix
{
private:
	int cols;
	int rows;
	vector<vector<float>> data;
public:
	Matrix();//此段conststructor开始是我根据视频写的，但是运行不起来，这是查找网上资料后，写出来的的
	Matrix(int cols, int rows);
	Matrix(int cols, int rows, const vector<vector<float>>& data);
	~Matrix()=default;

	friend Matrix operator*(const Matrix& A,const Matrix& B);
	friend Matrix operator*(const Matrix& A, float b);
	friend Matrix operator*(float a, const Matrix& B);
	friend std::ostream&operator<<(ostream&os,const Matrix& m);

	 Matrix operator=(const Matrix& other);
	 friend Matrix read_Matrix(const char* file_name);
};

#endif
