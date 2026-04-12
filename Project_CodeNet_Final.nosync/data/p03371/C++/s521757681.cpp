#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define PROB "PIZZA"
#define vi vector<int>

void init(){
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
}

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    if (X<Y){
        swap(X,Y);
        swap(A,B);
    }
    int res=min(A+B,2*C)*Y;
    X-=Y;
    res+=min(A,2*C)*X;
    cout<<res;
}

