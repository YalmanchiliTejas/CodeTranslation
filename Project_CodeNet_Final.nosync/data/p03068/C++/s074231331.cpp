#include<iostream>
using namespace std;
int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    char c=s[k-1];
    for(int i=0;i<n;i++)cout<<(s[i]==c?c:'*');
    cout<<endl;
    return 0;
}