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
	inp(long long, n, x, m);
	
	if (n == 1) { otp(x); return 0; }
	if (x == 0) { otp(0); return 0; }
	if (x == 1) { otp(n); return 0; }
	
	long long s = x;
	vector<int> a;
	decltype(a)::iterator it;
	a.push_back(x);
	for (int i = 1; i < n; i++) {
		x *= x;
		x %= m;
		if (x == 0) break;
		if (x == 1) { s += n - i; break; }
		if ((it = find(a.begin(), a.end(), x)) != a.end()) {
			int d = distance(it, a.end());
			s += (n - i) / d * accumulate(it, a.end(), 0ll);
			s += accumulate(it, it + (n - i) % d, 0ll);
			break;
		}
		a.push_back(x);
		s += x;
	}
	
	otp(s);
	
	return 0;
}
