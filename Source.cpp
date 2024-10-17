//Вариант 17 arctg(i+j)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double F(double i, double j)
{
	return atan(i + j);
}


int main()
{
	setlocale(LC_CTYPE, "ru");

	int n = 5, index = 0;
	double I = 1;

	double** A = new double* [n + 1]; //Инициализация матрицы nxn аij
	for (int i = 1; i <= n; i++)
	{
		A[i] = new double[n + 1];
	}
	double** R = new double* [n + 1]; //Инициализация матрицы nx2n
	for (int i = 1; i <= 2 * n; i++)
	{
		R[i] = new double[2 * n + 1];
	}

	for (int i = 1; i <= n; i++) //Заполнение матрицы аij элементами 
	{
		for (int j = 1; j <= n; j++)
		{
			A[i][j] = F(i, j);
			R[i][j] = A[i][j];
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) //Заполнение матрицы R элементами
	{
		for (int j = 6; j <= 2 * n; j++)
		{
			if (i + 5 == j) R[i][j] = 1;
			else R[i][j] = 0;
		}
	}

	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n; j++)
		{
			cout << R[i][j] << "\t";
		}
		cout << endl;
	}


	//Максимизация
	for (int j = 1; j <= n; j++) {
		index = j; //index - в итоге индекс максимального числа
		for (int k = j + 1; k <= n; k++) { //Перебор с 1 строчки 
			if (abs(R[k][j]) > abs(R[index][j])) {
				index = k;
			}
		}

		for (int i = 1; i <= n; i++) { //Перестановка
			double temp = R[j][i];
			R[j][i] = R[index][i];
			R[index][i] = temp;
		}
	}

	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2*n; j++)
		{
			cout << R[i][j] << "\t";
		}
		cout << endl;
	}

	
	// Примените метод Гаусса для преобразования матрицы

	for (int i = 1; i <= n - 1; i++) {
		for (int k = i + 1; k <= n; k++) {
			double coeff = R[k][i] / R[i][i];
			for (int j = i; j <= n; j++) {
				R[k][j] -= coeff * R[i][j];
			}
		}
	}

	
	cout << endl;
	// Вывод матрицы после применения метода Гаусса
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			cout << setw(10)  << R[i][j] << "\t";
		}
		cout << endl;
	}

	//Вычислеие определителя 
	for (int i = 1; i <= n; i++)
	{
		I *= R[i][i];
	}
	cout << endl << I;



}