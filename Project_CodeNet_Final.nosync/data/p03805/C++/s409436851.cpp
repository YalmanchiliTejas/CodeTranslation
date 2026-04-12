#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision


using namespace std;
bool routecheck(vector<int>& perm, vector<vector<int>>& G,int n){
    for (int i = 0; i < n-1; i++)
        {   
            int& j = perm[i];
            if(find(G[j].begin(),G[j].end(),perm[i+1]) == G[j].end()) return false;
        }
    return true;
}

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++)
    {
        int b,a; cin >> b >> a;
        b--; a--;
        G[b].push_back(a);
        G[a].push_back(b); 
    }
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
    }
    int count=0;
    do
    {   
        if(routecheck(perm,G,n)) count++;
    } while (next_permutation(perm.begin()+1,perm.end()));
    
    cout << count << endl;

    return 0;
}