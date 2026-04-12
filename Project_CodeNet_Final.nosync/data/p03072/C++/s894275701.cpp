#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int h[n];
    for(int i = 0;i<n;i++){
      cin >>h[i];
    }
    int sai = h[0];
    int k= 1;
    for(int i= 1;i<n;i++){
      if(h[i] >= sai){
        k+=1;
        sai = h[i];
      }
    }
    cout<<k;
    return 0;
}