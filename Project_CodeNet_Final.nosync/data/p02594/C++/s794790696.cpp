#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

#define length(a) (hypot((a).imag() , (a).real()))
#define point complex<ld>
#define perp(a) point((-(a).Y,(a).X))
#define dot(a,b) ( (conj(a)*(b)).real() )
#define cross(a,b) ( (conj(a)*(b)).imag() )
#define rotate0(p,ang) (p * exp(point(0,ang)) )

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x;
    cin >> x;
    if (x < 30) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}
