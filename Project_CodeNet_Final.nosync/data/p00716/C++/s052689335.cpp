using namespace std;

int main(){
	int M;
	cin>>M;
	for(int m = 1; m <= M; m++){
		int money, year, N;
		cin>>money>>year>>N;
		int mx;
		for(int n = 0; n < N; n++){
			int now_money = money;
			int interest = 0;
			int type; double ratio; int cost;
			cin>>type>>ratio>>cost;
			//calc
			for(int i = 0; i < year; i++){
				interest += (int)(ratio * now_money);
				if(type){
					now_money += interest;
					interest = 0;
				}
				now_money -= cost;
			}
			now_money += interest;
			if(n == 0 || mx < now_money)mx = now_money;
		}
		cout<<mx<<endl;
	}
	return 0;
}