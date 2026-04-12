#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n;
    string s;
    int k;
    cin >> n;
    cin >> s;
    cin >> k;
    char moji = s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]!=moji) s[i]='*';
    }
  cout << s << endl;
}
