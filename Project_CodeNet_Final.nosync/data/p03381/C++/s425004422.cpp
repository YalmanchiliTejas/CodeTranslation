#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long long n, eye, ubermed, untermed;
long long mylist[200001], origlist[200001];

int main() {
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>eye;
        mylist[i] = eye;
        origlist[i] = eye;
    }
    sort(mylist+1, mylist+n+1);
    untermed = mylist[n/2];
    ubermed = mylist[n/2 + 1];
    for(int i = 1; i <= n; i++) {
        if(origlist[i] <= untermed)
            cout<<ubermed;
        else
            cout<<untermed;
    cout<<endl;
    }
}