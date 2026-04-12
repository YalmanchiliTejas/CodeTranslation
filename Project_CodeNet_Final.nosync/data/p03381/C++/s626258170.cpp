#include <bits/stdc++.h>
using namespace std;

int a[200009];
int b[200009];
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {cin>>a[i];b[i]=a[i];}
    qsort(a,n,sizeof(int),compare);
    int m1,m2;
    m1=a[n/2-1];
    m2=a[n/2];
    for (int i=0;i<n;i++){
        if(b[i]<m2)
        {cout<<m2<<endl;}else{cout<<m1<<endl;}
    }
    
    
    
}