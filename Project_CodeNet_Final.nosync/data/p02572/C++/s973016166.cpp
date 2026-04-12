        #include<bits/stdc++.h>
        using namespace std;

        #define ll long long
        #define pb push_back
        #define printV(v) for(int i=0;i<(int)v.size();i++){cout << v[i]<< " ";} cout << endl
        #define printRev(v) for(int i=(int)v.size()-1;i >= 0;i--){cout << v[i] << " ";} cout << endl
        #define sortV(v) sort(v.begin(),v.end())
        #define revV(v) reverse(v.begin(),v.end())
    

        ll a,b,c,d,e,f,g,n,m,k,t,x,h,w,p,q,y;
        string str = "";
        ll mod = 1e9 + 7;
        const int N = 3009;
       
    

        void solve(){
            cin >> n;
            ll arr[n];
            ll sum = 0;
            for(int i=0;i<n;i++){
                cin >> arr[i];
                sum += arr[i];
                sum %= mod;
            }
            ll answer = sum*sum;
            answer %= mod;
            sum = 0;
            for(int i=0;i<n;i++){
                sum += arr[i] * arr[i];
                sum %= mod;
            }
            answer = (answer + mod - sum) % mod;
            if(answer % 2){
                answer = answer + mod;
            }
            answer /= 2;
            cout << answer << endl;

        }  
        


        int main(){
            ios_base::sync_with_stdio(false);

            
          

            int cases = 1;
            //cin >> cases;

            while(cases--) solve();
            return 0;

        }
