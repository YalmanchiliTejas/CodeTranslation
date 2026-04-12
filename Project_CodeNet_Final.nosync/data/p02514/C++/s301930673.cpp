#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
struct Gem{
	int x,y; //óìÌÀW
	int step; //ÝÏstep
};
int main(){
	int w,h;
	char s[10];
	for(;scanf("%d%d",&w,&h),w;){
		typedef vector<Gem> Gems;
		typedef vector<Gems> World;
		World world;
		Gem goal;
		int x,y;
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				scanf("%s",s);
				if(s[0]!='.'){
					if(s[0]=='G'){
						goal.x=x;
						goal.y=y;
						goal.step=0;
					}else{
						int n;
						if(s[0]=='S')
							n=0;
						else
							n=atoi(s);
						Gem g;
						g.x=x;
						g.y=y;
						g.step=0;
						if(world.size()<n+1)
							world.resize(n+1);
						world[n].push_back(g);
					}
				}
			}
		}
		world.push_back(Gems(1,goal));
		for(World::iterator iw=world.begin(),ib; ib=iw, ++iw!=world.end(); ){
			for(Gems::iterator iwg=iw->begin(); iwg!=iw->end(); ++iwg){
				int s=1e9;
				for(Gems::iterator ibg=ib->begin(); ibg!=ib->end(); ++ibg){
					s=min(s,ibg->step + abs(iwg->x - ibg->x) + abs(iwg->y - ibg->y));
				}
				iwg->step=s;
			}
		}
		printf("%d\n",world.back()[0].step);
	}
	return 0;
}