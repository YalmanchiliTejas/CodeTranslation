#include <iostream>
#include <climits>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 1000000007


using namespace std;
#define ll long long
#define dbg if(0)
#define ISRANGE(val,lo,hi) ((lo<=val)&&(val<hi))



int main(){
    ll ans;
    char a;
    cin >>a;

    {
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')cout <<"vowel"<<endl;
        else cout <<"consonant"<<endl;
    }

    dbg cout <<ans<<endl;

    return 0;

}