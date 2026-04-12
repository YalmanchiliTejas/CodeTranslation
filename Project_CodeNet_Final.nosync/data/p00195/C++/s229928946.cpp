#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <string>
#include <complex>
#include <functional>
using namespace std;
typedef pair<int,int> P;
double dat[100][100];
double dp[200][100];//動的計画法
int main(){
    int s1,s2,n,max,i;
    while(cin>>s1>>s2,s1){
        max=s1+s2;
        n=i=0;
        i++;
        while(i!=5){
            cin>>s1>>s2;
            if(max<s1+s2){
                max=s1+s2;
                n=i;
            }
            i++;
        }
        switch(n){
            case 0:
                cout<<"A ";
            break;
            case 1:
                cout<<"B ";
            break;
            case 2:
                cout<<"C ";
            break;
            case 3:
                cout<<"D ";
            break;
            default:
                cout<<"E ";
            break;
        }
        cout<<max<<endl;
    }
}
