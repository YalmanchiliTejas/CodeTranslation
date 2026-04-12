#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	int i,j,k,n;
	string S[50];
	char T[100],Temp1[100]={};
	string Temp;
	char A[1000]={};

	cin >> n;

	j=0;
	for(i=0;i<n;i++){
		cin >> T;
		sort(T,T+strlen(T));
		S[i]=T;
	}

	Temp=S[0];
	int l=0;
	for(i=1;i<n;i++){
		j=0;k=0;l=0;
		while((k<Temp.length())&&(j<S[i].length())){
		if(S[i][j]==Temp[k]){
			Temp1[l]=S[i][j];
			l++;j++;k++;
		}else if(Temp[k]>S[i][j]){
			j++;
		}else if(Temp[k]<S[i][j]){
			k++;
		}
		}
		Temp=Temp1;
		for(int m=0;m<100;m++){
			Temp1[m]=0;
		}
	}


	cout << Temp;
	cin >> n;

	return 0;
}
