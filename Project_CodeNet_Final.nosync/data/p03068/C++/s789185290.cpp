#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    char c = s[k - 1];
    for(int i = 0; i < n; ++i){
      if(s[i] != c){
        s[i] = '*';
      }
    }

    cout << s << endl;

    return 0;
}
