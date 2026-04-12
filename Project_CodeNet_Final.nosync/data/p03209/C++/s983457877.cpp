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
using namespace std;

typedef long long ll;

int main()
{
    ll N,X;
    cin >> N >> X;
    ll depth_nums[N+1][2];//深さ総数、パティ数
    depth_nums[0][0]=1;
    depth_nums[0][1]=1;
    for(int i=1; i<=N; i++){
        depth_nums[i][0]=2*depth_nums[i-1][0]+3;
        depth_nums[i][1]=2*depth_nums[i-1][1]+1;
    }
    ll ans=0;
    for(int i=N; i>=0; i--){
        if((depth_nums[i][0]+1)%2==0 && (depth_nums[i][0]+1)/2==X){
            ans+=depth_nums[i][1]/2+1;
            break;
        }else if(depth_nums[i][0]/2>=X) X--;
        else{
            ans+=depth_nums[i][1]/2+1;
            X-=depth_nums[i][0]/2+1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
