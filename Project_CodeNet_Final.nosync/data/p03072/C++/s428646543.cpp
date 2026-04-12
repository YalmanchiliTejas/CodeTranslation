#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,see=0;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        int count=1;
        for(int j=0;j<i;j++){
            if(h[j]>h[i]){
                count=0;
                break;
            }
        }
        if(count==1){
            see++;
        }
    }
    cout<<see<<endl;
}
