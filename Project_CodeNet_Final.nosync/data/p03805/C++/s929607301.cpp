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
#include <string>

using namespace std;

vector<vector<int>> v;
vector<int> base;
int N,M;
int ans = 0;

int main()
{
    cin >> N >> M;
    v.resize(N);
    
    for (int i = 0;i < N;i++){
        base.push_back(i);
    }
    
    int a,b;
    for (int i = 0;i < M;i++){
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 0;i < N;i++){
        sort(v[i].begin(),v[i].end());
    }

    do{
        for (int i = 0;i < N-1;i++){
            if (binary_search(v[base[i]].begin(),v[base[i]].end(),base[i+1])){
                ;
            }
            else{
                goto EXIT;
            }
        }
        ans++;
        EXIT:
        ;
    } while ( next_permutation(base.begin()+1,base.end()));
    
    cout << ans << endl;
}
