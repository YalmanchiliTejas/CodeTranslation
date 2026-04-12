#include <iostream>

namespace atutility {
	class atnum {
	public:

		const static int base = 1000000007;

		int num;

		atnum(int _num = 0)
			:num(_num % atnum::base)
		{}
		atnum(long long _num = 0)
			:num(_num% atnum::base)
		{}
		atnum& operator=(const int& n) {
			this->num = n % atnum::base;
			return *this;
		}
		atnum& operator=(const long long& n) {
			this->num = n % atnum::base;
			return *this;
		}

		atnum& operator+=(const int& n) {
			this->num = (int)(((long long)n + this->num) % atnum::base);
			return *this;
		}
		atnum& operator+=(const long long& n) {
			this->num = (int)((n + this->num) % atnum::base);
			return *this;
		}
		atnum& operator+=(const atnum& n) {
			this->num = (int)(((long long)n.num + this->num) % atnum::base);
			return *this;
		}

		atnum& operator*=(const int& n) {
			this->num = (int)(((long long)n * this->num) % atnum::base);
			return *this;
		}
		atnum& operator*=(const long long& n) {
			this->num = (int)((n * this->num) % atnum::base);
			return *this;
		}
		atnum& operator*=(const atnum& n) {
			this->num = (int)(((long long)n.num * this->num) % atnum::base);
			return *this;
		}

		atnum& operator/=(const int& n) {
			this->num = (int)((this->num * atnum::modinv(n, atnum::base)) % atnum::base);
			return *this;
		}
		atnum& operator/=(const long long& n) {
			this->num = (int)((this->num * atnum::modinv(n, atnum::base)) % atnum::base);
			return *this;
		}
		atnum& operator/=(const atnum& n) {
			this->num = (int)((this->num * atnum::modinv(n.num, atnum::base)) % atnum::base);
			return *this;
		}

		static long long modinv(long long a, long long m)
		{

			long long x = 0, y = 1, gcd = m;
			long long  px = 1, py = 0, pgcd = a;
			long long temp = 0;

			while (gcd > 0)
			{
				long long quotient = pgcd / gcd;

				temp = x;
				x = px - quotient * temp;
				px = temp;

				temp = y;
				y = py - quotient * temp;
				py = temp;

				temp = gcd;
				gcd = pgcd - quotient * temp;
				pgcd = temp;
			}

			while (px < 0) {
				px += atnum::base;
			}
			return px;
		}
		static atnum comb(long long a, long long b)
		{
			if (a < b) { return 0; }
			if (b > a / 2) { b = a - b; }
			if (b == 0) { return 1; }


			atnum ans = 1;
			for (int i = 0; i < b; i++) {
				ans *= a - i;
			}
			for (int i = 0; i < b; i++) {
				ans /= i + 1;
			}


			return ans;
		}
		static atnum comb(long long a, int b)
		{
			return atnum::comb(a, (long long)b);
		}
		static atnum comb(int a, int b)
		{
			return atnum::comb((long long)a, (long long)b);
		}
	};

	const atnum operator+(const atnum& lhs, const atnum& rhs)
	{
		return atnum(lhs) += rhs;
	}
	const atnum operator+(const atnum& lhs, int rhs)
	{
		return atnum(lhs) += rhs;
	}
	const atnum operator+(int lhs, const atnum& rhs)
	{
		return atnum(lhs) += rhs;
	}
	const atnum operator+(const atnum& lhs, long long rhs)
	{
		return atnum(lhs) += rhs;
	}
	const atnum operator+(long long lhs, const atnum& rhs)
	{
		return atnum(lhs) += rhs;
	}

	const atnum operator*(const atnum& lhs, const atnum& rhs)
	{
		return atnum(lhs) *= rhs;
	}
	const atnum operator*(const atnum& lhs, int rhs)
	{
		return atnum(lhs) *= rhs;
	}
	const atnum operator*(int lhs, const atnum& rhs)
	{
		return atnum(lhs) *= rhs;
	}
	const atnum operator*(const atnum& lhs, long long rhs)
	{
		return atnum(lhs) *= rhs;
	}
	const atnum operator*(long long lhs, const atnum& rhs)
	{
		return atnum(lhs) *= rhs;
	}

	const atnum operator/(const atnum& lhs, const atnum& rhs)
	{
		return atnum(lhs) /= rhs;
	}
	const atnum operator/(const atnum& lhs, int rhs)
	{
		return atnum(lhs) /= rhs;
	}
	const atnum operator/(int lhs, const atnum& rhs)
	{
		return atnum(lhs) /= rhs;
	}


	std::ostream& operator<<(std::ostream& lhs, const atnum& rhs)
	{
		lhs << rhs.num;
		return lhs;
	}
}

using namespace atutility;

using namespace std;

int N, M, K;

atnum calc(int A, int B);

int main()
{
	atnum ans = 0;

	cin >> N;
	cin >> M;
	cin >> K;

	ans = calc(N, M) + calc(M, N);
	ans *= atnum::comb(M * N - 2, K - 2);

	cout << ans << endl;

	return 0;
}

atnum calc(int A, int B)
{
	atnum ret = 0;
  
	for (int i = 1; i < A; i++) {
		atnum t = atnum(A - i) * i;
		ret += t;
	}

	ret *= B;
	ret *= B;

	return ret;
}