#include<iostream>
#include<vector>

using namespace std;

struct set{
	int many;
	int color;
};

int main()
{
	while (1){
		int n;
		cin >> n;
		if (!n){ break; }

		int white = 0;
		if (n >= 2){
			vector<set> stone;
			vector<set>::iterator p;

			int c1, c2;
			cin >> c1 >> c2;
			stone.push_back({ 2, c2 });

			for (int i = 1; i < n / 2; i++){
				int c1, c2;
				cin >> c1 >> c2;

				p = stone.end() - 1;
				if (c1 == c2){
					if (p->color == c2){
						p->many += 2;
					}
					else{
						stone.push_back({ 2, c2 });
					}
				}
				else{
					if (p->color == c2){
						p->many += 2;
					}
					else{
						p->color = p->color ? 0 : 1;
						p->many += 2;
						if (p != stone.begin()){
							(p - 1)->many += p->many;
							stone.erase(p);
						}
					}
				}
			}

			for (p = stone.begin(); p != stone.end(); p++){
				if (!p->color){
					white += p->many;
				}
			}
		}

		if (n % 2){
			int c;
			cin >> c;
			if (!c){ white++; }
		}

		cout << white << endl;
	}
	return 0;
}