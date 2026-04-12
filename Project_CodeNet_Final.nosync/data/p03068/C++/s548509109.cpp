#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
    int n,k;
    cin >> n;
    string s;
    cin >> s >> k;
    char c;
    c = s[k-1];
    for(int i=0;i<n;i++){
        if(s[i] != c) s[i] = '*';
    }
    cout << s << endl;
}