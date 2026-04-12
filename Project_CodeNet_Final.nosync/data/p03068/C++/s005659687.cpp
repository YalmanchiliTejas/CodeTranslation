#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char t;
    t = s.at(k-1);
    for(int i=0;i<s.size();i++){
        if (s.at(i)!=t){
            s.at(i)='*';
        }
    }
    cout << s << endl;
}
