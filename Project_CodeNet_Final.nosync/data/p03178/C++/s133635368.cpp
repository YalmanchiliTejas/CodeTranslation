#include<iostream>
#include<vector>

int main(){
	long long mod =1000000007;

	int n;
	int slen;
	std::string s;
	std::vector<std::vector<std::vector<long long>>> dpList;

	std::cin>>s;
	std::cin>>n;

	slen= s.size();
	dpList.resize(slen);

	for(int i=0; i<slen; i++){
		dpList[i].resize(n);

		for(int j=0; j<n; j++)
			dpList[i][j].resize(2, 0);
	}

	for(int i=1; i<=9; i++){
		dpList[0][i%n][0]++;

		if(s[slen-1]-'0'>=i)
			dpList[0][i%n][1]++;
	}

	for(int i=1; i<slen; i++){
		for(int k=0; k<n;k++){
			dpList[i][k][0]=dpList[i-1][k][0];
			if(s[slen-i-1]=='0')
				dpList[i][k][1]=dpList[i-1][k][1];
			else
				dpList[i][k][1]=dpList[i-1][k][0];
		}

		for(int j=1; j<=9; j++){
			for(int k=0; k<n; k++)
				dpList[i][(k+j)%n][0]= (dpList[i][(k+j)%n][0]+dpList[i-1][k][0])%mod;
			
			dpList[i][j%n][0]++;
		}

		for(int j=1; j<=9; j++){
			for(int k=0; k<n; k++){
				if(s[slen-i-1]-'0'>j)
					dpList[i][(k+j)%n][1]= (dpList[i][(k+j)%n][1]+dpList[i-1][k][0])%mod;

				if(s[slen-i-1]-'0'==j)
					dpList[i][(k+j)%n][1]= (dpList[i][(k+j)%n][1]+dpList[i-1][k][1])%mod;
			}

			if(s[slen-i-1]-'0'>=j)
				dpList[i][j%n][1]++;
		}
	}

	std::cout<<dpList[slen-1][0][1]<<std::endl;

	return 0;
}