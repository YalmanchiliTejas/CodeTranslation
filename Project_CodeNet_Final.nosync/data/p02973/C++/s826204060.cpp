#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

#define MAX_N 1000000
#define MAX_A 1000000001

using namespace std;
int main(){
    int n;
    int a[MAX_N];
    cin >> n;
    int colors[MAX_N];
    int color_min=MAX_A;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num_color=0;
    for(int i=0; i<n; i++){
        if(a[i]<=color_min){
            colors[num_color]=a[i];
            num_color++;
            color_min=a[i];
        }else{
            for(int j=0;j<num_color;j++){
                if(a[i]>colors[j]){
                    colors[j]=a[i];
                    if(j==num_color-1){
                        color_min=a[i];
                    }
                    break;
                }
            }
        }
    }
    cout<<num_color<<endl;
    return 0;
}