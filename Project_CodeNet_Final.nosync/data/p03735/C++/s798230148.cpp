#include<bits/stdc++.h>
using namespace std;

long long N;
pair<long long, long long> parr[200005];
long long mini, maxi;

int main(){
	cin >> N;
	mini = 1000000000;
	maxi = 1;
	for(long long i = 0; i < N; i++){
		cin >> parr[i].first >> parr[i].second;
		if(parr[i].first > parr[i].second){
			swap(parr[i].first, parr[i].second);
		}
		mini = min(mini, parr[i].first);
		maxi = max(maxi, parr[i].second);
	}

	if(N == 1){
		return 1;
	}

	long long Xmax = maxi, Ymax = 1;
	long long Xmin = mini, Ymin = 1000000000;
	long long ans = 1e18;

	//Xmin == mini && Xmax == maxi
	/*
	long long mapos1 = -1, mapos2 = -1;
	long long mipos1 = -1, mipos2 = -1;

	for(long long i = 0; i < N; i++){
		if(parr[i].second == maxi){
			if(mapos1 < 0){
				mapos1 = i;
			}else{
				mapos2 = i;
			}
		}


		if(parr[i].first == mini){
			if(mipos1 < 0){
				mipos1 = i;
			}else{
				mipos2 = i;
			}
		}
	}
	*/

	//Which Y should choose?
	//if((mapos2 > 0 )|| (mipos2 > 0) || (mapos1 != mipos1)){
		//            val    ,   pos
		vector<pair<long long, long long> > pairvec;
		long long pastmin = 1000000000;

		for(long long i = 0; i < N; i++){
			pairvec.push_back(make_pair(parr[i].first, i));
		}
		sort(pairvec.begin(), pairvec.end());


		Ymin = pairvec[0].first;
		Ymax = pairvec[pairvec.size() - 1].first;
		ans = min(ans, Ymax - Ymin) * (Xmax - Xmin);

		for(int i = 0; i < pairvec.size(); i++){
			//swap does not update minimum val
			if(pairvec[i].first >= pastmin){
				break;
			}
			pastmin = min(pastmin, parr[pairvec[i].second].second);

			if(i == pairvec.size() - 1){
				Ymin = pastmin;
			}else{
				Ymin = min(pastmin, pairvec[i+1].first);
			}

			Ymax = max(Ymax, parr[pairvec[i].second].second);

			ans = min(ans, (Ymax - Ymin) * (Xmax - Xmin));
		}
	//}


	//Xmin == mini && Ymax == maxi
	Xmax = 1;
	Ymax = 1;
	Xmin = 1000000000;
	Ymin = 1000000000;
	
	for(long long i = 0; i < N; i++){
		Ymin = min(Ymin, parr[i].second);
		Xmax = max(Xmax, parr[i].first);
	}

	ans = min(ans, (maxi - Ymin) * (Xmax - mini));

	cout << ans << endl;

}

