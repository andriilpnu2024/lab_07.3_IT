#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void Delete(int** a, int rowCount);
void Print(int** a, const int rowCount, const int colCount);
void rowmem(int** a, const int rowCount, const int colCount);
void Fill(int** a, int rowCount, int colCount);
void deleteROW(int** a, int& rowCount, const int colCount);
void deleteCOL(int**& a, const int rowCount, int& colCount);
void zsuv(int** a, int j, int i, int colCount);
void zsuv1(int** a, int i, int colrowCount);
int firstrowpos(int** a, int rowCount, int colCount);

int main()
{
	int rc;
	int cc;
	cout << "input RowCount:";
	cin >> rc;
	cout << "input ColCount:";
	cin >> cc;
	int** a = new int* [rc];
	rowmem(a, rc, cc);
	Fill(a, rc, cc);
	Print(a, rc, cc); 
	deleteROW(a, rc, cc); 
	deleteCOL(a, rc, cc);
	Print(a, rc, cc);
	if (firstrowpos(a, rc, cc) == -1)
		cout << "No positive elements!" << endl;
	else
		cout <<"First row with positive element: " << firstrowpos(a, rc, cc) << endl;
	Delete(a, rc);
}
void rowmem(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int firstrowpos(int** a, int rowCount, int colCount)
{
	int rowmin = -1;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (a[i][j] > 0)
			{
				rowmin = i;
				return rowmin;
			}
	}
	return rowmin;
}
void deleteROW(int** a, int& rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		int check = 1;
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] != 0)
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
		{
			delete[] a[i];
			zsuv1(a, i, rowCount);
			rowCount--;  // «меншуЇмо к≥льк≥сть р€дк≥в
			i--;
		}
	}
}
void deleteCOL(int**& a, const int rowCount, int& colCount)
{
	for (int j = 0; j < colCount; j++)
	{
		int check = 1;
		for (int i = 0; i < rowCount; i++)
		{
			if (a[i][j] != 0)
			{
				check = 0;
				break;
			}
		}

		// якщо стовпець складаЇтьс€ з нул≥в, видал€Їмо його
		if (check == 1)
		{
			for (int i = 0; i < rowCount; i++)
			{
				zsuv(a, j, i, colCount);
			}

			colCount--;
			j--;
		}
	}
}
void zsuv(int** a, int j, int i, int colrowCount)
{
	for (int k = j; k < colrowCount - 1; k++)
		a[i][k] = a[i][k + 1];
}
void zsuv1(int** a, int i, int colrowCount)
{
	for (int k = i; k < colrowCount - 1; k++)
		a[k] = a[k + 1];
}
void Fill(int** a, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}

}
void Delete(int** a, int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}