#include <iostream>

using namespace std;

int main(){
	int max,min,sum,ans,n;
	int s[101];

	while(1){
		//ÏÌú»
		max = 0;
		min = 1001;
		sum = 0;
		
		//f[^ZbgnÌüÍ
		cin >> n;
		if(n==0) break;//0 0ªüÍ³ê½çI¹

		//f[^ZbgÌ¾¯_ðüÍ
		for(int i=0 ; i<n ; i++){
			cin >> s[i];
		}
		//ÅålAÅ¬lÌlðÛ·é
		for(int i=0 ; i<n ; i++){
			if(max<s[i]) max = s[i];
			if(min>s[i]) min = s[i];
		}
		//ÅåÌ_ðÐÆÂr·é(0ðüêé)
		for(int i=0 ; i<n ; i++){
			if(max==s[i]){
				s[i]=0;
				break;
			}
		}
		//Å¬Ì_ðÐÆÂr·é(0ðüêé)
		for(int i=0 ; i<n ; i++){
			if(min==s[i]){
				s[i]=0;
				break;
			}
		}
		//_Ìvðßé
		for(int i=0 ; i<n ; i++){
			sum += s[i];
		}
		//_Ìv©ç½Ïðßé
		ans = sum/(n-2);
		//¦ÌoÍ
		cout << ans << endl;
	}

	return 0;
}