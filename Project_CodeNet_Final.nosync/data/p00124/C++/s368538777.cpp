#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct hoge{
    int s, n;
    string name;
    hoge(int s, int n, string name) : s(s), n(n), name(name) { }
};
bool operator < (const hoge &a, const hoge &b){
    return a.s != b.s ? a.s > b.s : a.n < b.n;
}

int main(void){
    int count=0;
    while(true){
        int n;
        cin >> n;
        if(count !=0 && n!=0) cout << "\n";
        count++;
        if(n==0) break;
        vector<hoge> v;
        string name;
        int win;
        
        for(int i=0; i<n; i++){
            cin >> name;
            ll w, l, d;
            cin >> w >> l >> d;
            win=3*w+d;
            v.push_back(hoge(win, i, name));
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            cout << v[i].name << "," << v[i].s << "\n";
        }
        
    }
     
     
    return 0;
}
