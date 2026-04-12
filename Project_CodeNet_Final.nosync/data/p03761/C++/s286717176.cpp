#include<iostream>
#include<string>
using namespace std;

int n;
int _index[26];
int s[50][26];
string ss;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ss;
        for(int j = 0; j < ss.length(); j++){
            s[i][(int)ss[j] - 97]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(i == 0){
               _index[j] = s[0][j];
            }else{
                if(_index[j] > s[i][j]){
                    _index[j] = s[i][j];
                }
            }
        }
    }
    for(int k = 0; k < 26; k++){
        for(int i = 0; i < _index[k]; i++){
            cout << (char)(k + 97);
        }
    }
    cout << endl;
}