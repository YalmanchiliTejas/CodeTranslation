#include "bits/stdc++.h"
using namespace std;
int main(){
    int R,G,B;
    cin>>R>>G>>B;
    cout<<((10*G+B)%4==0?"YES":"NO")<<endl;
}