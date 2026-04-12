# include <bits/stdc++.h>
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.begin(),vc.end()
# define  pi            pair <long, long>
# define  long          long long
# define  pb            push_back
# define  p_f           pop_front
# define  p_b           pop_back
# define  se            second 
# define  vec           vector
# define  dob           double
# define  flo           float
# define  fi            first 
# define  a_b_c_d_e     queue
# define  a_b_c_d_q     cout
# define  a_b_c_d_m     set
# define  a_b_c_d_z     cin 
# define  qa_qa_qa      map
using namespace std;
int main()
{
        //* Author: ~{ Oriyon }~
        //* Codeforces is the best !!!
        long test = 1;
        //cin >> test;
        for (int hello = 1; hello <= test; hello += 1)
        {
                long Qwert = 0, Qwerty = 0, Qwertyu, Qwerytyu;
                long n;
                cin >> n;
                vector <long> v(n);
                long ans = 0;
                for (int i = 0; i < n; ++i){
                    cin >> v[i];
                }
                vector <long> dp(n, 0);
                dp[0] = v[0];
                for (int i = 1; i < n; ++i){
                    dp[i] += dp[i - 1] + v[i];
                    dp[i] %= 1000000007;
                }
                for (int i = 1; i < n; ++i){
                    ans += dp[i - 1] * v[i];
                    ans %= 1000000007;
                }
                cout << ans;
        }   
        /*
        5
        2 3 5 7 11
        */
}
/*
*   👍&&👍&&👍&&👍
*   ||||||||||||||        HELLO WORLD !!!
*   👊&&👊&&👊&&👊
*/

