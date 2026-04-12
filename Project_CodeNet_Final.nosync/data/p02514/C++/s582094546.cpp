#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	double C[100][100];
	for ( int i=0; i<99; i++ )
	{
		C[i][0] = 1;
		for ( int j=1; j<i; j++ )
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		C[i][i] = 1;
	}

	int N,M,L;
	cin>>N>>M>>L;

	//vector<vector<double> > P(N,vector<double>(M+1));
	//

	//for ( int i=0; i<N; i++ )
	//{
	//	double p,t,v;
	//	cin >> p >> t >> v;

	//	p/=100;
	//	for ( int j=0; j<=M; j++ )
	//		P[i][j] = C[M][j] * pow(p,j) * pow(p,M-j),
	//		T[i][j] = L/v + t*j;
	//}

	vector<int> P(N), T(N), V(N);
	for ( int i=0; i<N; i++ )
		cin>>P[i]>>T[i]>>V[i];

	for ( int i=0; i<N; i++ )
	{
		double ans = 0;
		for ( int j=0; j<=M; j++ )
		{
			//	probability that i-th runner win with taking j times rest.
			double p = C[M][j]*pow(P[i]/100.,j)*pow(1-P[i]/100.,M-j);
			//cout << p << " " << C[M][j] << endl;

			for ( int k=0; k<N; k++ )
			if ( k!=i )
			{
				double t = 0;
				for ( int l=0; l<=M; l++ )
				//if ( L/V[k]+T[k]*l > L/V[i]+T[i]*j )
				if ( L*V[i]+T[k]*l*V[k]*V[i] > L*V[k]+T[i]*j*V[k]*V[i] )
					t += C[M][l]*pow(P[k]/100.,l)*pow(1-P[k]/100.,M-l);
				p *= t;
			}
			ans += p;
		}
		
		printf( "%.20f\n", ans );
	}
}


	