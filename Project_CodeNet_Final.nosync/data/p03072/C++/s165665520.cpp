#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,sum=1,top=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    top = a[0];
    
    for(int i=1;i<n;i++){
        if(a[i]>=top){
            sum ++;
            top = a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
