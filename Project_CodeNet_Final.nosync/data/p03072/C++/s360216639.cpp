#include<iostream>
using namespace std;

int main()
{
	int a,counter=0,tinggi=0;
	cin >> a;
	int arr[a+10];
	for(int i=0;i<a;i++)
	{
		cin >> arr[i];
		if(arr[i]>=tinggi)
		{
			counter++;
			tinggi=arr[i];
		}
	}
	cout << counter << endl;
}