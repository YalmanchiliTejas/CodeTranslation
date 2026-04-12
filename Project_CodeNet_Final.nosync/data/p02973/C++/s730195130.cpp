#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vector<ll> p_que;
    int ans=1;
    p_que.push_back(A[0]);
    for(int i=1; i<N; i++){
        auto itr=lower_bound(p_que.begin(), p_que.end(), A[i]);
        int dist=itr-p_que.begin();
        if(dist==0){
            ans++;
            p_que.insert(p_que.begin(), A[i]);
        }else{
            p_que[dist-1]=A[i];
        }
    }
    cout << ans << endl;
    

    return 0;
}