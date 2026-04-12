#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while(1){
    int n,s[100],m=100000,M=0,sum=0;
    cin >> n;
        if(n==0)break;
    for(int i=0;i<n;i++)    cin >> s[i];
    for(int i=0;i<n;i++){
        sum+=s[i];
        m=min(m,s[i]);
        M=max(M,s[i]);
    }
    cout << (sum-M-m)/(n-2)<<endl;
    }
    return 0;
}