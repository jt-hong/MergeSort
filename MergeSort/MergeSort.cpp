#include<iostream>

const int N = 10;
void MergeSort(int x[], int Left, int Right);
int x[N] = { 10,6,4,5,1,9,3,8,2,7 };

int main()
{
	MergeSort(x, 0, N-1);
	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i]<<"  ";
	}
    return 0;
}

void MergeSort(int x[], int Left, int Right)
{
	int *Temp = new int[N];
	int Center = (Left + Right) / 2;
	int RightEnd = Right;
	int LPos = Left, RPos = Center+1;
	int LeftEnd = RPos - 1;
	int TempPos = Left;
	int Element = Right - Left + 1;

	if (Left < Right)
	{
		MergeSort(x, Left, Center);
		MergeSort(x, Center + 1,Right);
	}
	while (LPos <= LeftEnd&&RPos <= Right)
	{
		if (x[LPos] <= x[RPos])
		{
			Temp[TempPos++] = x[LPos++];
		}
		else
		{
			Temp[TempPos++] = x[RPos++];
		}
	}
	while (LPos <= LeftEnd)
		Temp[TempPos++] = x[LPos++];
	while (RPos <= RightEnd)
	{
		Temp[TempPos++] = x[RPos++];
	}
	for (int k = 0; k < 10; k++)
		std::cout<<Temp[k]<<"   ";
	std::cout << std::endl;
	for (int i = 0; i < Element; i++, RightEnd--)
	{
		x[RightEnd] = Temp[RightEnd];
	}
	delete[] Temp;
}
