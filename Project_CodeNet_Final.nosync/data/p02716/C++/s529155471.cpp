    #include <cstdio>
    #include <algorithm>
     
    using namespace std;
     
    const int MAXN=2e5+10;
    int N;
    int arr[MAXN];
     
    typedef long long int ll;
     
    ll dp[MAXN];
     
    int main(){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",arr+i);
     
        // for(int i=1;i<=N;i++) printf("%d ",arr[i]);
        // putchar('\n');
     
        
        if (N%2){
            for(int i=1;i<=N;i++) 
                if (i%2) dp[i]=dp[i-1]+arr[i]; else dp[i]=dp[i-1]-arr[i];
     
            int lower_bound=1;
            int ans_l,ans_r;
            ll max_prefix=-1,min_seg=dp[1];
            for(int i=1;i<=N;i+=2){
                if (dp[i-1]>max_prefix){
                    max_prefix=dp[i-1];
                    lower_bound=i;
                }
     
                if(dp[i]-max_prefix<=min_seg){
                    min_seg=dp[i]-max_prefix;
                    ans_r=i;
                    ans_l=lower_bound;
                }
            }
     
            ll sum=0;
            for(int i=1;i<ans_l;i+=2) sum+=arr[i];
            for(int i=ans_l+1;i<=ans_r;i+=2) sum+=arr[i];
            for(int i=ans_r+2;i<=N;i+=2) sum+=arr[i];
     
            // printf("lower_bound=%d,upper_bound=%d\n",ans_l,ans_r);
     
            printf("%lld\n",sum);
        }else{
            ll sum=0ll;
            ll temp=0ll;
            for(int i=1;i<N;i+=2) temp+=arr[i];
            sum=temp;
            for(int i=N-1;i>=1;i-=2) {
                temp+=arr[i+1];
                temp-=arr[i];
                sum=max(sum,temp);
            }

     
            printf("%lld\n",sum);
        }
     
     
        return 0;
    }