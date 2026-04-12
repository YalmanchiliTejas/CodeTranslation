#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
typedef pair<int, int> P;

int main(){
    char c;
    cin >> c;
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') out("vowel");
    else out("consonant");
}
