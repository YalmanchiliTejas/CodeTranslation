#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    cin >> n;
    int a[n];
    long long s=0;
    long long c=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
        s%=1000000007;
    }
    for(int i=0;i<n;i++){
        s-=a[i];
        if(s<0) s+=1000000007;
        c+=a[i]*s;
        c%=1000000007;
    }
    cout << c << endl;
    return 0;
}