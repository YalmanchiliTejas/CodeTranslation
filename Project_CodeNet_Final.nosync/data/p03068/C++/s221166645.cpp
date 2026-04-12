#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    int t;
    cin>>t;
    for(int i=0;i<n;i++){
        if(a[i]!=a[t-1]) a[i]='*';
    }
    cout<<a<<endl;
    return 0;
}
