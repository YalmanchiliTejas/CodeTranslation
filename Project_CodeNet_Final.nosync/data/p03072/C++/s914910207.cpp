#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	
	cin>>n;
	int x;
	int cont=0;
	int y=0;
	for(int i=0;i<n;i++) 
	{
		cin>>x;
		if(x>=y){
			 cont++;
			 y=x;
		}
		
	}
	cout<<cont;
	
	return 0;
}

