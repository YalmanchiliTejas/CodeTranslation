#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    while(n){
        int a[n];
        int mini = INT_MAX, maxi = INT_MIN;
        int mincnt=0, maxcnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i]==mini)  mincnt++;
            else if(a[i]==maxi) maxcnt++;
        }
        //cout<<mini<<" "<<mincnt<<" "<<maxi<<" "<<maxcnt<<endl;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==mini && mincnt>1){
                sum +=a[i];
                cnt++;
                mincnt--;
            }
            else if(a[i]==maxi && maxcnt>1){
                sum +=a[i];
                cnt++;
                maxcnt--;
            }
            else if((a[i]!=mini) && (a[i]!=maxi)){
                sum +=a[i];
                cnt ++;
            }
        }
        cout<<sum/cnt<<endl;
        cin>>n;
    }
    return 0;
}


