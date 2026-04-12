#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5+2;
pair<int,int> input[N];

ll findWhenMinMax(int n,int maxi,int rem) {
   int mini = input[1].first;
   int rem2 = input[1].second;
   ll ret = 4e18;
   const int inf = 2e9;
   priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
   int R = 0;
   for(int i=2;i<=n;++i) {
      pq.push(input[i]);
      R = max(R,input[i].first);
   }
   pq.push(make_pair(rem2,inf));
   pq.push(make_pair(rem,inf));
   R = max(R,max(rem,rem2));
   ll len = maxi - mini;
   while(!pq.empty()) {
      pair<int,int> cur = pq.top();
      pq.pop();
      ret = min(ret, len * ( R - cur.first));
      if(cur.second == inf) {
         break;
      }
      pq.push(make_pair(cur.second,inf));
      R = max(R, cur.second);
   }
   return ret;
}

ll findWhenMinMaxDiff(int n,int maxi,int rem) {
   ll ret= 4e18;
   int yourMini = min(rem,input[1].first);
   int yourMaxi = max(rem,input[1].first);
   int myMini = input[1].second;

   for(int i=2;i<=n;++i) {
      int curYourMaxi = yourMaxi;
      int curMyMini = myMini;
      if(i!=n) {
         curYourMaxi = max(curYourMaxi, input[n].first);
      }
      curYourMaxi = max(curYourMaxi,input[i].second);
      curMyMini = min(curMyMini,input[i].first);
      yourMaxi = max(yourMaxi,input[i].first);
      myMini = min(myMini,input[i].second);
   }
   ll tmp = yourMaxi - yourMini;
   tmp *= (maxi - myMini);
   ret = min(ret,tmp);
   return ret;
}
void solve() {
   int n;
   scanf("%d",&n);
   if(n==1) {
      printf("0\n");
      return;
   }
   int ind = -1,maxi = 0;
   for(int i=1;i<=n;++i) {
      scanf("%d%d",&input[i].first,&input[i].second);
      if(input[i].first>input[i].second) {
         swap(input[i].first,input[i].second);
      }
      if(maxi< input[i].second) {
         ind = i;
         maxi = input[i].second;
      }
   }
   int rem = input[ind].first;
   for(int i=ind;i<n;++i) {
      swap(input[i],input[i+1]);
   }
   --n;
   sort(input+1,input+n+1);
   //case 1
   ll ret= findWhenMinMax(n,maxi,rem);

   //case2
   ret = min(ret, findWhenMinMaxDiff(n,maxi,rem));
   printf("%lld\n", ret);
}

int main() {
   //freopen("input.txt","r",stdin);
   solve();
}