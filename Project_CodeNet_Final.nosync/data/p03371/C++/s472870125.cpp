#include<vector>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	vector<long long>ooi_vector(2);
	vector<long long>sukunai_vector(2);
	bool AB_use = ((A + B) >= (2 * C));//trueならABを使う
	long long ooi = max(A, B);
	long long sukunai = min(A, B);

	long long kazu_ooi = max(X, Y);
	long long kazu_sukunai = min(X, Y);
	vector<long long>kazu_ooi_vector(2);
	vector<long long>kazu_sukunai_vector(2);

	if (kazu_ooi == X)
	{

		kazu_ooi_vector[0] = A;
		kazu_ooi_vector[1] = X;

		kazu_sukunai_vector[0] = B;
		kazu_sukunai_vector[1] = Y;
	}
	else if (kazu_ooi == Y)
	{

		kazu_ooi_vector[0] = B;
		kazu_ooi_vector[1] = Y;

		kazu_sukunai_vector[0] = A;
		kazu_sukunai_vector[1] = X;
	}
	long long res = 0;
	if (AB_use)
	{
		if (A < C || B < C)
		{
			 res = C * (kazu_sukunai_vector[1] * 2)+kazu_ooi_vector[0]*(kazu_ooi_vector[1]-kazu_sukunai_vector[1]);
			cout << res << endl;
		}
		else
		{

			 long long horixyu = C * (kazu_ooi_vector[1]*2);//ここがやばい
			 long long horixyu_2 = C * (kazu_sukunai_vector[1] * 2) + kazu_ooi_vector[0] * (kazu_ooi_vector[1] - kazu_sukunai_vector[1]);
			 if (horixyu >= horixyu_2)
			 {
				 res = horixyu_2;
			 }
			 else
			 {
				 res = horixyu;
			 }
			cout << res << endl;
		}
	}
	else
	{
		res = A * X + B * Y;
		cout <<res << endl;
	}
	


}