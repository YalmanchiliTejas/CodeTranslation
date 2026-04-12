    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define all(x) x.begin(), x.end()
    typedef vector<int> vi;
    typedef pair<int,int> ii;
    typedef long long ll;
     
    const ll inf = 3e18 + 5;
     
    const int MAXN = 1 << 19;
    int N = 400000;
    int seg[2 * MAXN], A[MAXN];
    typedef vector<vi> vvi;
    
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    
        char c;
        cin >> c;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cout << "vowel";
        else
            cout << "consonant";
    }