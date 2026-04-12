#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    char moji = s.at(k - 1);
    for(int i = 0; i < n; i++){
        if(s.at(i) != moji){
            s.at(i) = '*';
        }
    }
    cout << s <<endl;
}