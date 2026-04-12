#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm> 
using namespace std;

# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;

int main()
{
    int n ; cin >> n;

    int h[20];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    int res=0;
    for(int i=n-1;i>=0;i--){
        bool flg=true;
        for(int j=0;j<i;j++){
            if(h[i]<h[j]) flg=false;
        }
        if(flg) res++;
    }
    p(res)
}