//#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include <stdint.h>
#include <chrono>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ios>     // left, right

#include <vector>
#include <array>
#include <list>
#include <map>

using namespace std;
/*オプション*/               namespace {
	#define DEBUG_PRINT
	#define DEBUG_TIME
	#define DEBUG_TESTCASE
	#define NAME_PROBLEM "test_problem.txt"
}
/*マクロ*/                   namespace {
	/*数*/                   namespace {
		typedef long long	    ll;
		typedef  intmax_t     intt;
		typedef uintmax_t    uintt;
		typedef unsigned int uint;
		#define  MAXX  INTMAX_MAX
		#define  MINN  INTMAX_MIN
		#define UMAXX UINTMAX_MAX
		#define UMINN UINTMAX_MIN
		#define PI M_PI
		#define MOD 1000000007 //10^9+7
		#define ALL(list) list.begin(),list.end()
		
		long strtol_my(const string& str) {
			return strtol(str.c_str(), nullptr, 10);
		}

		template<typename T>
		intt sum(const vector<T>& list) {
			return accumulate(ALL(list), 0);
		}

		template<typename T>
		double average(const vector<T>& list) {
			return static_cast<double>(accumulate(ALL(list), 0)) / list.size();
		}
    }
	/*繰り返し*/             namespace {
		#define  REP(i, n)		for(auto i = 0; i < (n); i++)
		#define FORI(i,list)	for(auto i = 0; i < (list).size(); i++)
		#define FORL(i,m,a,n)	for(auto i = (m); i <=(n); i+=(a))	//CMDのfor/l

		#define  REPR(i, n)		for(auto i = (n)-1; i >= 0; i--)
		#define FORIR(i,list)	for(auto i = (list).size()-1; i >= 0 ; i--)

		#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
	}
	/*入出力*/               namespace {
		template<class... Args>
		void input_args(Args&... args) {
		}
		template<class Head, class... Args>
		void input_args(Head& head, Args&... args) {
			cin >> head;
			input_args(args...);
		}

		template<typename T>
		vector<T> input_list(intt n) {
			vector<T> list;
			for (auto i = 0; i < n; i++) {
				T tmp;
				cin >> tmp;
				list.push_back(tmp);
			}
			return list;
		}

		vector<string> input_split_string() {
			vector<string> list;
		    string line, s;
			getline(cin, line);
		    istringstream iss(line);
		    while (iss >> s) {
		        list.push_back(s);
		    }
			return list;
		}
		
		template<class... Args>
		void print_args(const Args&... args) {
			cout << endl;
		}
		template<class Head, class... Args>
		void print_args(const Head& head, const Args&... args) {
			cout << head << ' ';
			print_args(args...);
		}
	}
	/*その他*/               namespace {
		#define INN(a,n,b) ((a)<=(n)&&(n)<=(b))

		template<typename FIRST, typename SECOND>
		vector<pair<FIRST, SECOND>> list_from(const map<FIRST, SECOND>& map) {
			return vector<pair<FIRST, SECOND>>(ALL(map));
		}

		template<typename FIRST, typename SECOND>
		vector<pair<FIRST, SECOND>> sort_map_by_value(const map<FIRST, SECOND>& map) {
			auto list = list_from(map);
			sort(ALL(list),[](const pair<FIRST, SECOND>& a, const pair<FIRST, SECOND>& b)->bool {
				return a.second < b.second;
			});
			return list;
		}
	}
	/*デバッグ、数値確認用*/ namespace {
		#if defined(MY_DEBUG) && defined(DEBUG_PRINT)
		  #define DBG(...) print_args(__VA_ARGS__)
		#else
		  #define DBG(...)
		#endif
	}
	/*デバッグ、時間計測用*/ namespace {
		#if defined(MY_DEBUG) && defined(DEBUG_TIME)
		  #define TIME_REC(name) TimeRec::add_record(#name)
		  #define TIME_STOP()    TimeRec::add_record("")
		  #define TIME_SHOW()    TimeRec::show()
		#else
		  #define TIME_REC(name)
		  #define TIME_STOP()
		  #define TIME_SHOW()
		#endif

		using namespace chrono;
		using Time = system_clock::time_point;

		class TimeRec {
		public:
			static void add_record(const char *name);
			static void show();
		private:
			struct Record {
				const char* name;
				Time time;
			};
			static vector<Record> records;
		};
		vector<TimeRec::Record> TimeRec::records;

		void TimeRec::add_record(const char *name) {
			records.push_back({name, system_clock::now()});
		}
		void TimeRec::show() {
			if (records.empty()) { return; }

			for (auto i = records.begin(), next = i + 1; next != records.end(); i = next++) {
				double time = duration_cast<chrono::microseconds>(next->time - i->time).count() / 1000.0;
				printf("%s\t%7.2f[ms]\n", i->name, time);
			}
		}
	}
	/*デバッグ、オート入力*/ namespace {
		#if defined(MY_DEBUG) && defined(DEBUG_TESTCASE)
		  #define SET_CIN(file_name) set_cin(file_name)
		#else
		  #define SET_CIN(file_name)
		#endif
		
		void set_cin(const string& file_name) {
			static ifstream in(file_name);
			cin.rdbuf(in.rdbuf());
		}
	}
}
void Main();
int main() {
	SET_CIN(NAME_PROBLEM);
	TIME_REC(start);
	Main();
	TIME_STOP();
	TIME_SHOW();

	return 0;
}




void Main() {
	uintt n;
	input_args(n);
	auto list = input_list<uintt>(n);
	uintt sum = 0;
	for(auto&& a: list) {
		sum += a;
	}
	uintt ans = 0;
	for (auto &&a : list) {
		sum -= a;
		ans = (ans + ((sum % MOD) * (a % MOD)) % MOD) % MOD;
	}

	print_args(ans);
}
