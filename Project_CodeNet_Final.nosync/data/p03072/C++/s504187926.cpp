#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> height(N,0);
    for(int i=0;i<N;i++)
        cin>>height[i];
    int last=height[0];
    int res=1;
    for(int i=1;i<N;i++){
        if(height[i]>=last){
            res++;
            last=height[i];
        }
    }
    cout<<res;
}
