#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <vector>
#include <map>



#define IOS                    ios::sync_with_stdio();cin.tie(0);
#define tc()                int tc;scanf("%d",&tc);while(tc--)
#define endl                "\n"
#define FLOAT_COM(a,b)      if(abs(a-b)==1e-9)
#define VI                  vector<int>
#define VLL                 vector<long long>
#define PB                  push_back
#define MP                  make_pair



using namespace std;

int i,j,k,l,temp;

void shomoy(){
    #ifndef ONLINE_JUDGE
        cerr<<"\nTime  :"<<1.0*clock()/CLOCKS_PER_SEC<<"  s\n";
    #endif

}

bool isprime(int n){
    int f;
    for(f=2;f*f<=n;f++){
        if(n%f==0)
            return false;
    }
    return true;
}


                      /*Driver Code Startes Here*/
int main(){IOS

    int n;
    scanf("%d",&n);
    if(n>=30){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    

    

shomoy();
return 0;
}