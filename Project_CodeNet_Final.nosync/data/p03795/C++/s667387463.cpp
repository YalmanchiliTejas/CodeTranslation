#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin>>a;
    int b=(a-a%15)/15;
    cout<<800*a-200*b<<endl;
}
