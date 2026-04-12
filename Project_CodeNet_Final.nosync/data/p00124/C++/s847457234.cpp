#include <iostream>
#include <algorithm>

struct Team {
	std::string country;
	int score;
};
bool operator > (const Team& t1, const Team& t2) { return t1.score > t2.score; }

int main()
{
	int n; std::string sn;
	bool first = true;
	while (getline(std::cin, sn)) {
		n = std::stoi(sn);
		if (n==0) break;
		if (!first) std::cout << std::endl;
		if (first) first = false;
		Team* teams = new Team[n];
		std::string country;
		int w, l, d;
		std::string buf;
		for (int i=0; i<n; i++) {
			getline(std::cin, buf);
			int offset = 0;
			int pos = buf.find(' ', 0);
			country = buf.substr(0, pos);
			offset = pos + 1;
			pos = buf.find(' ', offset);
			w = std::stoi(buf.substr(offset, pos-offset));
			offset = pos + 1;
			pos = buf.find(' ', offset);
			l = std::stoi(buf.substr(offset, pos-offset));
			d = std::stoi(buf.substr(pos+1));
			
			teams[i].country = country;
			teams[i].score = 0;
			teams[i].score += 3*w;
			teams[i].score += d;
		}
		std::sort(teams, teams + n, std::greater<Team>() );
		for (int i=0; i<n; i++) {
			std::cout << teams[i].country << "," << teams[i].score << std::endl;
		}
		
		delete[] teams;
	}
	return 0;
}


