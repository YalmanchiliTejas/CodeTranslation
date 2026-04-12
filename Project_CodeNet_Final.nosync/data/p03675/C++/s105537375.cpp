#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
 
int main(void){
   int n;
   cin >> n;
   int a[n];
   int b[n];
   for(int i = 0; i < n; i++)
    cin >> a[i];
   int count = 0;
   int check=0;
    while(count<n){
        if(count%2==0)
            check=count/2;
        else if(count%2!=0)
            check=(n-1)-(count/2);
        b[check]=a[(n-1)-count];
        count++;
    }
    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}