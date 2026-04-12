#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector <int> v[n];
    vector <int> l;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    for(int i=1;i<n;i++){
        l.push_back(i);
    }
    
    int ans=0;


    do{
        bool z=true;
        int save=0;
        for(int x : l){
            auto result=find(v[save].begin(), v[save].end(),x);
            if(result == v[save].end()){
                z=false;
                break;
            }
            else{
                save=x;
                continue;
            }
        }
        if(z) ans++;
    }while(next_permutation(l.begin(),l.end()));

    cout << ans << "\n";



}