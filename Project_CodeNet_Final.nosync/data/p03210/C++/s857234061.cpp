#include <iostream>
#include <stdlib.h>
#include <utility>
using namespace std;
int int_sort(const void*a,const void *b) {
    return *(  int *) b - *(int *) a;
    //qsort(b, a, sizeof(long long int), int_sort);
}
int main() {
     int n;
     int out[100000];
     cin >> n ;
    //for (int i = 0; i < m; i++) {
    // cin >> p >> y;
    if(n==3 ||n==5 ||n==7)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;


}