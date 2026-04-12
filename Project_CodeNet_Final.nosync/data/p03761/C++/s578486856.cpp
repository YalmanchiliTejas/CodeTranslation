#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int a;
    cin >> a;
    vector<int> v(28,0);
    string t;
    cin >> t;
    for(int i=0;i < t.size();i++){
        v.at(t.at(i)-'a')++;   
    }
    
    for(int i=1;i < a;i++){
        string s;
        cin >> s;
        vector<int> u(28,0);
        for(int j=0;j < s.size();j++){
            u.at(s.at(j)-'a')++;
        }

        for(int k=0;k < 28;k++){
            v.at(k)=min(u.at(k),v.at(k));
        }
    }
    for(int l=0;l < 28;l++){
        while(v.at(l)!=0){
            char c = 'a'+l;
            cout << c;
            v.at(l)--;
        }
    }
    cout << endl;
}