#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int main(){
    int n,count=1;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        int f=1;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                f=0;
            }
        }
        if(f)
            count++;
    }
    cout<<count;
}
