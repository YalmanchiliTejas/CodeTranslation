#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    map<int,vector<int>> mp;
    int a,b;
    
    for(int i = 0; i < M;i++){
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    
    
    vector<int> v;
    for(int i = 1;i <= N;i++) v.push_back(i);
    
    
    int cont = 0;
    bool lflag;
    int fcont = 0;
    do {
        
        if(v[0]==1){
            // for(auto u:v){
            //     cout <<right << setw(2)<<u;
            // }
            // cout <<endl;
            
            
            lflag = true;
            for(int i = 0; i < v.size() - 1; i++){
                fcont = 0;
                for(auto u:mp[v[i]]){
                   
                    if(u == v[i+1]) fcont++;
                    //  cout <<"i:"<<i<< v[i]<< v[i+1] << endl;
                    //  cout <<"fcont:"<<fcont<<endl;
                }
            
                if(fcont == 0)lflag = false;
            }
        
        
            if(lflag){
                cont++;

            }
        }    
    } while (next_permutation(v.begin(), v.end()));

    cout << cont << endl;
    
}
