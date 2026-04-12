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
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

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



int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int sum = a*x + b*y;
    int max = (x>y)?x:y;

    for(int i=2;i<=2*max;i+=2){
        int subsum = 0;
        if(x-(i/2)>0 && y-(i/2)>0){
            subsum = a*(x-(i/2))+b*(y-(i/2))+c*i;
        }else if(x-(i/2)<=0 && y-(i/2)<=0){
            subsum = c*i;
        }else if(x-(i/2) <= 0){
            subsum = b*(y-(i/2)) + c*i;
        }else if(y-(i/2) <= 0){
            subsum = a*(x-(i/2)) + c*i;
        }

        if(sum>subsum){
            sum = subsum;
        }
    }

    cout << sum << endl;
    return 0;
}