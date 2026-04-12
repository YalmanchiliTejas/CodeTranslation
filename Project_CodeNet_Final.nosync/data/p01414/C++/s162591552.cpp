#include<queue>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

#define bit(i,j) (1<<((i)<<2)+(j))

int main(){
	int n; scanf("%d",&n);
	vector<int> stamp;
	rep(i,n){
		int h,w; scanf("%d%d",&h,&w);
		for(int k=1-h;k<4;k++) for(int l=1-w;l<4;l++) for(int c=1;c<=3;c++) {
			int S=0;
			for(int y=k;y<k+h;y++) for(int x=l;x<l+w;x++) {
				if(0<=y && y<4 && 0<=x && x<4) S|=bit(y,x);
			}
			stamp.push_back(S);
		}
	}

	sort(stamp.begin(),stamp.end());
	stamp.erase(unique(stamp.begin(),stamp.end()),stamp.end());

	int goal[4][4];
	rep(i,4){
		char s[5]; scanf("%s",s);
		rep(j,4){
			if(s[j]=='R') goal[i][j]=0;
			if(s[j]=='G') goal[i][j]=1;
			if(s[j]=='B') goal[i][j]=2;
		}
	}

	bool visited[1<<16];
	rep(S,1<<16) visited[S]=(S==0);

	int ans;
	queue< pair<int,int> > qu; qu.push(make_pair(0,0));
	while(1){
		int S=qu.front().first;
		int cnt=qu.front().second; qu.pop();

		if(S==(1<<16)-1){ ans=cnt; break; }

		rep(k,stamp.size()) rep(c,3) {
			int S2=S;
			rep(i,4) rep(j,4) if(stamp[k]&bit(i,j)) {
				if(goal[i][j]==c) S2|=bit(i,j);
				else              S2&=~bit(i,j);
			}
			if(!visited[S2]){
				visited[S2]=true;
				qu.push(make_pair(S2,cnt+1));
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}