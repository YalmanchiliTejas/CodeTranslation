#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    int i;
    cin >> s;
    int a;
    cin >> a;
    char c = s[a-1];
    for(i = 0; i< n; i++){
        if(s[i] != c){
            s[i] = '*';
        }
    }
    for(i =0; i<n ;i++){
        cout << s[i];
    }
}
