#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[105]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        int check=1;
        for(int j=1;j<=i;j++){
            if(check==0) break;
            if(a[j]>a[i]) check=0;
        }
        if(check) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
