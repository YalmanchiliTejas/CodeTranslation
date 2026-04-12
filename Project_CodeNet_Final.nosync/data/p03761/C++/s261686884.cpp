#include <iostream>
#include <string>

using namespace std;

int n;
string s[50];
int c[50][26];

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            c[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size();j++){
            c[i][s[i][j]-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<n;j++){
            if(c[0][i] > c[j][i]){
                c[0][i] = c[j][i];
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<c[0][i];j++){
            cout << (char)(i+'a');
        }
    }
    cout << endl;
    return 0;
}