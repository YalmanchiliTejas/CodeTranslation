#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    int s=a.size();
    for(int i=0;i<s-1;i++){
        if(a[i]=='A'&&a[i+1]=='C'){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}