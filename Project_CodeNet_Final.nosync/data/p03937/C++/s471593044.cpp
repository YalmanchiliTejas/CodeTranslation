/*input
4 5
##...
.###.
.###.
...##
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int H, W;

	cin >> H >> W;
	// cout << "H:" << H << " W:" << W << endl;

	vector<string> field(H);

	for(int i=0;i<H;i++){
		cin >> field[i];
	}

	int sharp_count = 0;

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			sharp_count += field[i].substr(j,1) == "#";
		}
	}

	// cout << sharp_count << endl;

	if(sharp_count == (H+W-1)){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}

	return 0;
}
