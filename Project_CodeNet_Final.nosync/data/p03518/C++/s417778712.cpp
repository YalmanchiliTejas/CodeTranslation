#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;

int n,p[maxn];
vector<int> sol;

void swap(int &a,int &b) {
    int tg=a;
    a=b;
    b=tg;
}

void go(int k) {
    sol.push_back(k);
    for (int i=k;i<n;i++) swap(p[i],p[i-k]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++) cin>>p[i];
    bool tested = true;
    while (tested) {
        tested = false;
        for (int i=0;i<n;i++) {
            if (p[0]!=0 && p[n-1] > p[0]) {
                tested = true;
                go(n-1);
            }
            go(1);
        }
      //  for (int i=0;i<n;i++) cout<<p[i]<<" ";
       // cout<<endl;
    }
    while (p[0]!=0) go(1);
    cout<<sol.size()<<endl;
    for (int i=0;i<sol.size();i++) cout<<sol[i]<<endl;
}
