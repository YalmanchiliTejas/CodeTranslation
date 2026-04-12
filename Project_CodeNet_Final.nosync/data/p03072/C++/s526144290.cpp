# include <bits/stdc++.h>
# define pb push_back
# define ll long long
# define fi first
# define se second
# define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
# define mkp make_pair
//# define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"

using namespace std;

ll q , w , e , z ;


int main()
{
	speed;

    int n ;
    cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a[i] ;
    }
    z+=1;
    for(int i = 1 ; i < n ; i ++ ){
            q = 0;
        for(int j = i ; j > -1 ; j -- ){
            if(a[j]>a[i]){
                q=1;
            }
        }
        if(q == 0 ){
            z++;
        }
    }

    cout<< z ;

	time;
}
