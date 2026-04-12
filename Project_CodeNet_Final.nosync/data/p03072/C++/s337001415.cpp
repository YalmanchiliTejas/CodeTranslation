#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c=0;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int k=a[0];
    for(int i =1; i < n; i++){
        if(k<=a[i]){
          c++;
          k=a[i];
        }
    }
    printf("%d\n",c+1);
    return 0;
}


