#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>



using namespace std;

int main() {
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int max=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(max<=h[i]){
            max=h[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

