#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char ans = s[k - 1];
    for(int i = 0; i < n; i++){
        if(s[i] != ans){
            s[i] = '*';
        }
    }
    cout << s << endl;
}