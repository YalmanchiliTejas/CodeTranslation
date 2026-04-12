#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

void
print_vec (vector<int> exp)
{
	for (auto x:exp)
	{
		if (x == -5)
			cout << "+";
		else if (x == -6)
			cout << "*";
		else if (x)
			cout << x;
		else
			cout << "error";
	}
	cout <<endl;
}

vector<int>
str_to_vec (string exp)
{
	vector<int> v;
	for (int i = 0; i < exp.size(); i++)
	{
		int c = exp[i] - '0';
		if (0 <= c || c <= 9) // number
			v.push_back(c);
		else 
			v.push_back(c);
	}
	return v;
}

int
mis_cal (vector<int> exp)
{
	int num = exp[0];
	bool add, mul;
	add = mul = false;
	for (int i = 1; i < exp.size(); i++)
	{
		if (exp[i] == -5) // plus
			add = true;
		else if (exp[i] == -6) // mul
			mul = true;
		else 
		{
			if (add)
			{
				num += exp[i];
				add = false;
			}
			else if (mul)
			{
				num *= exp[i];
				mul = false;
			}
			else
			{
				cout << "error" <<endl;
				exit(1);
			}
		}
	}
	return num;
}

int
cal (vector<int> exp)
{
	int num = exp[0];
	vector<int> v;
	bool add, mul;
	add = mul = false;
	for (int i = 1; i < exp.size(); i++)
	{
		if (mul)
		{
			num *= exp[i];
			mul = false;
		}
		else if (add)
		{
			v.push_back(num);
			v.push_back(-5);
			num = exp[i];
			add = false;
		}
		else if (exp[i] == -6)
			mul = true;
		else if (exp[i] == -5)
			add = true;
		else if (0 <= exp[i] && exp[i] <= 9)
		{
			num = exp[i];
		}
		else 
		{
			cout << "error"<<endl;
			exit(1);
		}
	}
	v.push_back(num);
#ifdef D
	cout << "cal";
	print_vec(v);
#endif

	return mis_cal(v);
}

	int
main (void)
{
	int bob_ans;
	string str_exp;
	cin >> str_exp >> bob_ans;

	vector<int> vec_exp = str_to_vec(str_exp);
#ifdef D
	print_vec(vec_exp);
	cout << "mis_cal " << mis_cal(vec_exp) << endl;
	cout << "cal     " << cal(vec_exp) << endl;
#endif
	int m, c;
	m = mis_cal(vec_exp); c = cal(vec_exp);
	if (bob_ans == m && bob_ans == c)
		cout << "U" <<endl;
	else if (bob_ans == c)
		cout << "M" <<endl;
	else if (bob_ans == m)
		cout << "L" <<endl;
	else
		cout << "I" <<endl;

	return 0;
}

