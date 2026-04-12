#include <iostream>
#include <string>
using namespace std;
int main(){
    int k,n;
    string s;
    cin >> n >> s >> k;
    for(auto it=s.begin(); it!=s.end(); it++){
        cout << ((*it==s[k-1])? *it : '*');
    }
    cout << endl;
}