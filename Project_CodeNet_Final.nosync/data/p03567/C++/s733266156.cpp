#include<bits/stdc++.h>

using namespace std;
char a[11111];
int main(){
    while(cin >> a){
        if(strstr(a, "AC") != 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}