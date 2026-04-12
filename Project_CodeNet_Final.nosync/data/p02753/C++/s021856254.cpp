#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    cout<<(s.find('A')!=string::npos&&s.find('B')!=string::npos?"Yes":"No")<<'\n';
    return 0;
}