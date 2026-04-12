#include <vector>
#include <iostream>

using Matrix = std::vector<std::vector<char>>;

int main(int argc, char *argv[]) {
	int height = 0;
	int width = 0;

	std::cin >> height >> width;

	//
	//  初期化間違いでえらい目に...
	//	wrong -> std::vector<char>('#', width)
	//
	Matrix matrix(height,
		std::vector<char>(width, '#')
	);

	// 消すべき行の位置を知る
	std::vector<bool> erase_y;
	char current_cell;
	for (int y = 0; y < height; y++) {
		bool all_white(true);
		for (int x = 0; x < width; x++) {
			std::cin >> current_cell;
			if (current_cell != '.') {
				all_white = false;
			}
			matrix[y][x] = current_cell;
		}
		erase_y.push_back(all_white);
	}

	//  消すべき列の位置を知る
	std::vector<bool> erase_x;
	for (int x = 0; x < width; x++) {
		bool all_white(true);
		for (int y = 0; y < height; y++) {
			if (matrix[y][x] != '.') {
				all_white = false;
			}
		}
		erase_x.push_back(all_white);
	}

	//  消すべき行および列を除いて全て出力
	for (int y = 0; y < height; y++) {
		if (erase_y[y] == false) {
			for (int x = 0; x < width; x++) {
				if (erase_x[x] == false) {
					std::cout << matrix[y][x];
				}
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
