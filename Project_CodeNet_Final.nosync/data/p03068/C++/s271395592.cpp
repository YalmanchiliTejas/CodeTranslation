#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    string s;
    int n, k;
    cin >> n >> s >> k;
    char ex = s[k-1];
    for(int i=0; i<n; i++){
        if(s[i] != ex){
            s[i] = '*';
        }
    }
    cout << s << endl;
}