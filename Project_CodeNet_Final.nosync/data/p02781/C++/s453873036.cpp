            #include <bits/stdc++.h>
            using namespace std;
            vector<int> num;
            int k;
            int dp[109][109][2];
            int call(int pos,int m,int f)
            {
                // cout << pos << " " << m << " " << f << endl;
                if(dp[pos][m][f]!=-1)return dp[pos][m][f];
                if(pos==num.size())
                {
                    if(m==k)return 1;
                    else return 0;
                }
                int limit;
                if(f==0)limit=num[pos];
                else limit=9;
                int res=0;
                for(int digit=0; digit<=limit; digit++)
                {
                    int nf=f;
                    int nm=m;
                    if(f==0&&digit<limit)nf=1;
                    nm=m;
                    if(digit != 0)
                        res+=call(pos+1,nm+1,nf);
                    else
                        res+=call(pos+1,nm,nf);
                }
                return dp[pos][m][f]=res;
            }
            int solve(string s)
            {
               
                num.clear();
                int n = s.size();
                for(int i = 0 ;i < n; i++)
                    num.push_back(s[i] - '0');
                memset(dp,-1,sizeof(dp));
                // reverse(num.begin(),num.end());
                return call(0,0,0);

            }

            int main()
            {
                string s;
                cin >> s;
                cin >> k;

                cout << solve(s) << endl;
                
            }