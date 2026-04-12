#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include<bitset>
#include<stdio.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 100000000;

bool isOK(int a[],int index,int key){
    if(a[index] >= key){
        return true;
    }else{
        return false;
    }
}

int binary_search(int a[],int n,int key){
    int left = -1;
    int right = n;

    while(right-left>1){
        int mid = left + (right - left)/2;
        if(isOK(a,mid,key)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int factrial(int n){
    if(n==0){
        return 1;
    }else{
        return n*factrial(n-1);
    }
}

int main(void){
    int n,m;
    int count = 0;
    cin >> n >> m;

    vector<vector<int> > dist(n,vector<int>(m));
    vector<int> distnum(n);
    vector<int> order(n);
    rep(i,n){
        order[i] = i;
    }
    rep(i,n){
        distnum[i] = 0;
    }
    rep(i,n){
        rep(j,m){
            dist[i][j] = -1;
        }
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        dist[a-1][distnum[a-1]++] = b-1;
        dist[b-1][distnum[b-1]++] = a-1;
    }
    do{
        rep(i,n-1){
            bool flag2 = false;
            rep(j,distnum[order[i]]){
                if((dist[order[i]][j]==order[i+1]) && order[0]==0){
                    flag2 = true;
                }
            }
            if(!flag2){
                break;
            }
            if(flag2 && i==n-2){
                count++;
            }
        }
    }while(next_permutation(order.begin(),order.end()));

    cout << count << endl;
    return 0;
}
