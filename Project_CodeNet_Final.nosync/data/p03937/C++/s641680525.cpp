#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
        int num1=0,num2=0,e=0;
        char test1[8][8];
        
        cin>>num1>>num2;
        for(int i=0;i<num1;i++){
        	for(int q=0;q<num2;q++){
        		cin>>test1[i][q];
        	}
        }
        for(int w=0;w<num1-1;w++){
        	for(int r=0;r<num2;r++){
        	e=w+1;
        	if(test1[w][r]=='#'){
        		for(int t=0;t<r;t++){
        			if(test1[e][t]=='#'){
        				cout<<"Impossible\n";
        				goto AA;
        			}
        		}
        	}
        	}
        }
        cout<<"Possible\n";
        AA:;
	return 0;
}
