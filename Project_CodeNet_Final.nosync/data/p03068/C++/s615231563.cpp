#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    string str;
    int n,k;
    cin >> n;
    cin >> str;
    cin >> k;
    char ch = str[k-1];
    for(int i=0;i<n;i++){
        if(str[i]!=ch)  cout << "*";
        else   cout << str[i];
    }
    return 0;
}