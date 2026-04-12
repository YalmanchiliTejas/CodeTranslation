#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3005

int n;
ll *arr, dp[MAX][MAX];

/*
dpi][j] -> what will be the max score if i have option to pick i th item from left or jth item from right.

Now point samajna yeh hai ki jo bhi element pick karta hai voh corresponding user ke score mein add ho jata hai.
Second this If i assume ki iss samay mera pass do hi item hai, them agr mein ith(0) elemnt pick kiya, toh 0 item mera
score mein add ho jayeyga and now qki abb dusare player ki turn hogi toh, voh jo pick karega uske socre mein add ho jaeyga
So total diff will be x-y.

Same thing I assume, and I pick one element one from left or one from right and add corresponding val into my score and call for rec to 
tell what will be score of next player if i pick these option element.

Yeh pointer thoda confusion ki kaise player ki turn maintain ho rahi hai.
Dekh X->total score of first, Y->total score of second

So if at a point I assume there are only 2 element and first player pick one so add this into his score and call to cal
score of second player if he has arr with first element removed(as first player pick this item) and function return me 
his score and i substract it from first player score. This is how rec handle turm of players.

As rec give me the final score second player will get if first player pick either ith or jth item.
*/

ll solve(int i, int j){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll opt1 = arr[i]-solve(i+1, j);
    ll opt2 = arr[j]-solve(i, j-1);

    return dp[i][j] = max(opt1, opt2);
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n-1)<<endl;
}

void bottomUp(){
    memset(dp, 0, sizeof(dp));

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i>j) dp[i][j]=0;
            else{
                dp[i][j] = max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int main(){
    fstIO;
    cin>>n;
    arr = new ll[n+1];
    ip(arr, n);
    // topDown();
    bottomUp();
    return 0;
}