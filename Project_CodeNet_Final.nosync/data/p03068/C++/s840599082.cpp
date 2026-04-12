#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    string s;
    int t;
    cin >> n;
    cin >> s;
    cin >> t;

    for(int i = 0; i < n; i++){
        if(s[i] != s[t-1]){
            s[i] = '*';
        }
    }
    cout << s << endl;
}