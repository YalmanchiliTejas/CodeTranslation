#include <iostream>
#include <algorithm>
using namespace std;

int function(int n, int a, int b[]){
    int start = 0; int end = n;
    while(end-start>=1){
        int i = (start+end)/2;
        if(b[i]==a)
            return i;
        else if(b[i]<a)
            start = i;
        else
            end = i;
    }
}

int main(void){
    int n;
     cin >> n;
    int num[n];
    int fake[n];
    int ans[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
        fake[i]=num[i];
    }
    
    sort(num, num+n);
    int check = n/2;
    int mid = num[check];
    int now;
    for(int i = 0; i < n; i++){
        now = function(n, fake[i], num);
        if(now>=check)
            ans[i] = num[check-1];
        else if(now<check)
            ans[i] = num[check];
        cout << ans[i] << endl;
    }
    
    return 0;
}