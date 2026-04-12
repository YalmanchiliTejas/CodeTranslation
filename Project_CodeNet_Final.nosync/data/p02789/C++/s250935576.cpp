
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cctype>
#include<random>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long int I;

int keta(int a){
    int count=0;
    while(a!=0){
        a/=10;
        count++;
    }
    return count;
}


int main(){
    long long int n,m;
    cin>>n>>m;
    if(n==m){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    

    return 0;
} //カモンAC