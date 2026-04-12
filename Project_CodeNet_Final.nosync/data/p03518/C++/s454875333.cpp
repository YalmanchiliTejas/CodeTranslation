#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
int p[202];
vector<int> ans;
void nuo(int k){
    ans.push_back(k);
    for(int i=k; i<n; i++) swap(p[i], p[i-k]);
}
void move(int k){
    if(k==0){
        nuo(n-1);
        return;
    }
    for(int i=0; i<k-1; i++){
        nuo(n-1);
        nuo(1);
    }
    nuo(n-1);
    for(int i=0; i<n-k; i++){
        nuo(1);
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    for(int i=1; i<n-1; i++){
        while(p[n-1]!=i){
            nuo(1);
        }
        for(int j=0; j<n; j++){
            if(p[j]==i-1){
                move((j+1)%n);
            }
        }
    }
    while(p[0]!=0){
        nuo(1);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<endl;
    return 0;
}