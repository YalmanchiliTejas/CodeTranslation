#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#define inf 1000000007
using namespace std;

int main(void){
    int n;
    cin >> n;
    string s[n];
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    char a[26]; a[0]='a';
    int ans = 0;
    for(int i = 1; i < 26; i++)
        a[i] = a[i-1]+1;
    //for(int i = 0; i < n; i++)
      //  cout << s[i] << endl;
    for(int i = 0; i < 26; i++){
        ans = inf;
        for(int j = 0; j < n; j++){
            count = 0;
            for(int k = 0; k < s[j].length(); k++){
                if(a[i]==s[j][k]) 
                count++;
            }
            ans = min(ans, count);
        }
        for(int b = 0; b < ans; b++)
            cout << a[i];
    }
    cout << endl;
    return 0;
}