#include<iostream>

#include<string>
#include <algorithm> 
using namespace std;

int main()
{
    int n,k;
    string s;
    cin >> n >> s >> k;

    string s_k = s.substr(k-1,1);
    string res = "";
    for(int i = 0 ; i < n ; i++){
        if(s_k==s.substr(i,1)) res += s_k;
        else res += "*";
    }
    cout << res << endl;
}