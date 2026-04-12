#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 10005
#define NUM 10

struct Info{

	int X,Y;
};

int N;
Info info[SIZE];

double calc_dist(double x1,double y1, double x2,double y2){

	if(fabs(floor(x1/10)-floor(x2/10)) < EPS){

		if(fabs(y1-y2) < EPS){

			return fabs(x1-x2);

		}else{

			return fabs(y1-y2)+min((x1-floor(x1/10)*10)+(x2-floor(x2/10)*10),
					((floor(x1/10)+1)*10-x1)+((floor(x2/10)+1)*10-x2));
		}

	}else if(fabs(floor(y1/10)-floor(y2/10)) < EPS){

		if(fabs(x1-x2) < EPS){

			return fabs(y1-y2);

		}else{

			return fabs(x1-x2)+min((y1-floor(y1/10)*10)+(y2-floor(y2/10)*10),
								((floor(y1/10)+1)*10-y1)+((floor(y2/10)+1)*10-y2));
		}

	}else{

    	return fabs(x1-x2)+abs(y1-y2);
    }
}

int main(){

	scanf("%d",&N);

	int min_add = BIG_NUM,max_add = -BIG_NUM;
	int min_sub = BIG_NUM,max_sub = -BIG_NUM;

	for(int i = 0; i < N; i++){

		scanf("%d %d",&info[i].X,&info[i].Y);

		min_add = min(min_add,info[i].X+info[i].Y);
		min_sub = min(min_sub,info[i].X-info[i].Y);

		max_add = max(max_add,info[i].X+info[i].Y);
		max_sub = max(max_sub,info[i].X-info[i].Y);
	}

	int mid_add = (min_add+max_add)/2,mid_sub = (min_sub+max_sub)/2;
	int base_X = (mid_add+mid_sub)/2,base_Y = (mid_add-mid_sub)/2;


	base_X -= (base_X)%10;
	base_Y -= (base_Y)%10;


	double ans = BIG_NUM;

	for(int x = base_X-NUM; x <= base_X+NUM; x += 10){
		for(double y = base_Y-NUM; y <= base_Y+NUM; y += 0.5){

			double max_dist = -BIG_NUM;

			for(int i = 0; i < N; i++){
				max_dist = max(max_dist,calc_dist(info[i].X,info[i].Y,x,y));
			}
			ans = min(ans,max_dist);
		}
	}

	for(int y = base_Y-NUM; y <= base_Y+NUM; y += 10){
		for(double x = base_X-NUM; x <= base_X+NUM; x += 0.5){

			double max_dist = -BIG_NUM;

			for(int i = 0; i < N; i++){
				max_dist = max(max_dist,calc_dist(info[i].X,info[i].Y,x,y));
			}
			ans = min(ans,max_dist);
		}
	}

	printf("%.10lf\n",ans);

	return 0;
}

