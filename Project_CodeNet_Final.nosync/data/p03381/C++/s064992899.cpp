#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end() 

int const N = 200001;
int n, an[N];
pair<int,int> v[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v, v+n);
    int f = v[n/2].first, s = v[n/2-1].first;
    for(int i = 0; i<n; ++i){
        if(i < n/2)an[v[i].second] = f;
        else an[v[i].second] = s;
    }
    for(int i = 0; i<n; ++i)printf("%d\n", an[i]);
}