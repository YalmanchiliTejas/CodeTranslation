#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<functional>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    a-=c;
    cout<<a/(b+c)<<endl;
    return 0;
}