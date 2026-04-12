#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

int main()
{
    int n;
    cin >> n;

    int a[mx5];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    map<int, int> id;

    int l = a[0], r = a[0];
    int it = 1, i = 1, j = n - 1;
    LL a1 = 0, a2 = 0;

    while(1){
        if(it % 2){
            int A = a[j];
            int B = a[j - 1];

            if(id[j])
                break;

            if(id[j - 1]){
                int x = abs(l - A), y = abs(r - A);
                if(x > y)
                    a1 += x;
                else
                    a1 += y;
                break;
            }

            a1 += abs(l - A) + abs(r - B);
            l = A, r = B;
            id[j] = id[j - 1] = 1;
            j -= 2;
        }
        else{
            int A = a[i];
            int B = a[i + 1];

            if(id[i])
                break;

            if(id[i + 1]){
                int x = abs(l - A), y = abs(r - A);
                if(x > y)
                    a1 += x;
                else
                    a1 += y;
                break;
            }

            a1 += abs(l - A) + abs(r - B);
            l = A, r = B;
            id[i] = id[i + 1] = 1;
            i += 2;
        }
        it++;
    }

    id.clear();
    it = 1, l = r = a[n - 1], i = 0, j = n - 2;

    while(1){
        if(it % 2 == 0){
            int A = a[j];
            int B = a[j - 1];

            if(id[j])
                break;

            if(id[j - 1]){
                int x = abs(l - A), y = abs(r - A);
                if(x > y)
                    a2 += x;
                else
                    a2 += y;
                break;
            }

            a2 += abs(l - A) + abs(r - B);
            l = A, r = B;
            id[j] = id[j - 1] = 1;
            j -= 2;
        }
        else{
            int A = a[i];
            int B = a[i + 1];

            if(id[i])
                break;

            if(id[i + 1]){
                int x = abs(l - A), y = abs(r - A);
                if(x > y)
                    a2 += x;
                else
                    a2 += y;
                break;
            }

            a2 += abs(l - A) + abs(r - B);
            l = A, r = B;
            id[i] = id[i + 1] = 1;
            i += 2;
        }
        it++;
    }

    cout << max(a1, a2) << '\n';
    return 0;
}
