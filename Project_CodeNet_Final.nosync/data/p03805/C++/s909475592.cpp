#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>

using namespace std;
;

int n,m;
vector<int> d[10];



bool reached(vector<int> v)
{
    bool ans = true;
    for (int i = 0;i < n-1;i++){
        if(binary_search(d[v[i]].begin(),d[v[i]].end(),v[i+1])){
            ;
        }
        else {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    int a,b;
    int ans = 0;
    
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        cin >> a >> b;
        a--;
        b--;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    
    for (int i = 0;i < n;i++){
        sort(d[i].begin(),d[i].end());
    }
    vector<int> v;
    for (int i = 0;i < n;i++){
        v.push_back(i);
    }
    
    do {
        if(reached(v)){
            ans++;
        }
    } while (next_permutation(v.begin()+1,v.end()));
    
    cout << ans << endl;
}
