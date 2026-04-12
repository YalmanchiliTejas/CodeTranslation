#include <cstdio>
#include <iostream>
using namespace std;



int main() {
    int n;
    cin>>n;
    int height[n];
    for (int i=0;i<n;i++) cin>>height[i];
    int sum = 0;
    int max = 0;
    int j = 0;
    while(j<n){
        if (height[j]>=max) {
            max = height[j];
            sum ++;
        }
        j++;
    }
    cout<<sum;
}
