#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a = "aiueo";
    char c; cin >> c;
    for(int i = 0; i < 5; i++)
    {
        if(c==a[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    
}
