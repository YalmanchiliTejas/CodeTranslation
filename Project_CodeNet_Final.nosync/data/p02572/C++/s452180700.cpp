#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <array>
#include <algorithm>
#include <utility>
#include <numeric>


using namespace std;


template <class ...Args>
void Input(Args &...args)
{
	(cin >> ... >> args);
}

template <class T>
void InputArray(std::size_t size, T &t)
{
	t.resize(size);
	for (auto &e : t) {
		cin >> e;
	}
}

template <class ...Args>
void InputArray(std::size_t size, Args &...args)
{
	(InputArray(size, args), ...);
}

template <class ...Args>
void InputVerticalArray(std::size_t size, Args &...args)
{
	(args.resize(size), ...);
	for (int i = 0; i < size; i++) {
		((cin >> args[i]), ...);
	}
}

template <class ...Args>
void Output(const Args &...args)
{
	((cout << args << ' '), ...) << endl;
}

template <class ...Args>
void OutputVertical(const Args &...args)
{
	((cout << args << endl), ...);
}

template <class T>
void OutputArray(const T &t)
{
	for (const auto &e : t) {
		cout << e << ' ';
	}
	cout << endl;
}

template <class ...Args>
void OutputArray(const Args &...args)
{
	(OutputArray(args), ...);
}

template <class ...Args>
void OutputVerticalArray(const Args &...args)
{
	for (int i = 0; i < min({ args.size()... }); i++) {
		((cout << args[i] << ' '), ...) << endl;
	}
}


#define inp(type, ...) \
	type __VA_ARGS__; \
	Input(__VA_ARGS__)

#define inpa(type, size, ...) \
	type __VA_ARGS__; \
	InputArray((size), __VA_ARGS__)

#define inpva(type, size, ...) \
	type __VA_ARGS__; \
	InputVerticalArray((size), __VA_ARGS__)

#define otp(...) \
	Output(__VA_ARGS__)

#define otpv(...) \
	OutputVertical(__VA_ARGS__)

#define otpa(...) \
	OutputArray(__VA_ARGS__)

#define otpva(...) \
	OutputVerticalArray(__VA_ARGS__)

#define rep(counter, range) \
	for (int (counter) = 0; (counter) < (range); (counter)++)

#define repi(range) \
	rep(i, range)

#define rrep(counter, range) \
	for (int (counter) = (range) - 1; (counter) >= 0; (counter)--)

#define rrepi(range) \
	rrep(i, range)

#define repc(element, container) \
	for (auto &(element) : (container))

#define repe(container) \
	repc(e, container)

#define all(container) \
	(container).begin(), (container).end()

#ifdef __CCR__
#	define dlog(x) clog << #x " = " << x << endl
#else
#	define dlog(x)
#endif



int main()
{
	inp(int, n);
	inpa(vector<int>, n, a);
	
	long long sum = accumulate(all(a), 0ll) % 1000000007;
	long long result = 0;
	repi(n - 1) {
		sum -= a[i];
		if (sum < 0) sum += 1000000007;
		result += a[i] * sum;
		result %= 1000000007;
	}
	
	otp(result);
	
	return 0;
}
