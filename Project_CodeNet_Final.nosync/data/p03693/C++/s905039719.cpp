#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>
#include <fstream>
#include <queue>
#include <cstdio>
using namespace std;
#define fol(i,n) for (int i=0;i<n;i++)
#define db(a) cout << a<< endl;
typedef pair <int,int>P;
using namespace std;

int main(){
    int a,b,c;
    cin >>a>>b>>c;
    int d = 10*b+c;
    if (d%4) cout << "NO"<<endl;
    else cout << "YES"<<endl;
    return 0;
}
