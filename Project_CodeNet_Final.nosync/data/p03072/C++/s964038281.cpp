#include <bits/stdc++.h>
using namespace std;
int a,b,c,answer,big;
int main() {
    // insert code here...
    cin>>a;
    cin>>b;
    big=b;
    answer=1;
    for (int i=1; i<a; i++) {
        cin>>c;
        if (c>=big) {
            answer++;
        }
        big=max(big,c);
    }
    cout<<answer<<endl;
    return 0;
}