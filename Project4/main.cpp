#include<iostream>
#include<fstream>
#include"matrix.h"

using namespace std;

//从文件中读取矩阵
Matrix read_Matrix(const char* file_name) {
	ifstream in(file_name);
	if (!in.is_open())
	{
		cout << "打开文件失败" << endl;
		exit(EXIT_FAILURE);
	}
	int rows = 0, cols = 0;
	float temp;
	Matrix m;
	m.rows = 0;
	m.cols = 0;
	vector<float>row_data;
	vector<vector<float>>data;
	while (in >> temp) {
		row_data.push_back(temp);
		cols++;
		m.cols = max(m.cols, cols);
		if (in.peek() == '\n') {
			data.push_back(row_data);
			rows++;
			m.rows = max(rows, m.rows);
			row_data.clear();
			cols = 0;
		}
	}
	in.close();
	m.data = data;
	return m;
}
int main() {
	float a = 3.0, b = 2.0;
	Matrix A = read_Matrix("C:\\Users\\星火\\Downloads\\CS205_C_CPP_Lab-main\\CS205_C_CPP_Lab-main\\project2\\data\\mat-A-64.txt");
	Matrix B = read_Matrix("C:\\Users\\星火\\Downloads\\CS205_C_CPP_Lab-main\\CS205_C_CPP_Lab-main\\project2\\data\\mat-B-64.txt");

	Matrix C = A * B;
	Matrix D = A * b;
	Matrix E = a * B;

	cout << "Matrix C=A*B:" <<C<< endl;
	cout << "Matrix D=A*b:" << D << endl;
	cout << "Matrix E=a*B:" << E << endl;

	return 0;
}