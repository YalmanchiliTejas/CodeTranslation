#include <iostream>
using namespace std;

int main() {
    int i,j,n;
    int f=0;
    int sum=0;
    cin >> n;
    int h[n];
    for(i=0; i<n; i++){
        cin >> h[i];
    }
    for(i=0; i<n; i++){
        for(j=0; j<i; j++){
            if(h[j]>h[i]){f=1;}
        }
        if(f==0){sum++;}
        f=0;
    }
    cout << sum << endl;
    return 0;
}