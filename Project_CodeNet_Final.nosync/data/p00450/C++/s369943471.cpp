#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;

int main()
{
	int n;
	while (scanf("%d", &n) && n){
		vector<P> line;
		for (int i = 0; i < n; i++){
			int col;
			scanf("%d", &col);
			if (!i) line.push_back(make_pair(col, 1));
			else if (i % 2 == 0){
				if (line.size() && line[line.size() - 1].first == col){
					line[line.size() - 1].second++;
				}
				else line.push_back(make_pair(col, 1));
			}
			else {
				if (line[line.size() - 1].first == col) line[line.size() - 1].second++;
				else {
					line[line.size() - 1].first = col;
					line[line.size() - 1].second++;
					if (line.size() > 1 && line[line.size() - 2].first == col){
						line[line.size() - 2].second += line[line.size() - 1].second;
						line.erase(line.end() - 1, line.end());
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < line.size(); i++) if (line[i].first == 0) sum += line[i].second;
		
		printf("%d\n", sum);
	}
	return (0);
}