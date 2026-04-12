#include<bits/stdc++.h>

using namespace std;

int n,k,i,j,d,suma,odp;
int tablica[10003][103];
char slowo[10003];

int main() {
	cin >> slowo+1 >> k;
	n=strlen(slowo+1);
	tablica[1][0]=1;
	for(i=2;i<=n;i++){
		for(d=0;d<=9;d++){
			for(j=0;j<=k;j++){
                tablica[i][(d+j)%k]=(tablica[i][(d+j)%k]+(tablica[i-1][j]+1000000007)%1000000007)%1000000007;
			}
        }
    }
	for(i=1;i<=n;i++){
		for(j=0;j<slowo[i]-'0';j++){
            odp=(odp+(tablica[n-i+1][(-(suma+j)%k+k)%k]+1000000007)%1000000007)%1000000007;
		}
		suma=(suma+slowo[i]-'0')%k;
	}
	if(suma){
        odp=(odp+(-1+1000000007)%1000000007)%1000000007;
	}
    cout << odp;
	return 0;
}
