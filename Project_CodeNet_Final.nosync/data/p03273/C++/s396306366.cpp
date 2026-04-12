#include <iostream>
#include <sstream>
#include <array>

using data_t = std::array<std::array<char, 100>, 100>;

bool isBlankRow(data_t& a, int H, int W, int row)
{
	for (int w = 0; w < W; ++w)
		if ('#' == a[row][w])
			return false;

	return true;
}

bool isBlankCol(data_t& a, int H, int W, int col)
{
	for (int h = 0; h < H; ++h)
		if ('#' == a[h][col])
			return false;

	return true;
}

void deleteRow(data_t& a, int H, int W, int row)
{
	for (int h = row; h < H - 1; ++h)
	{
		a[h] = a[h + 1];
	}
}

void deleteCol(data_t& a, int H, int W, int col)
{
	for (int h = 0; h < H; ++h)
		for (int w = col; w < W - 1; ++w)
		{
			a[h][w] = a[h][w + 1];
		}
}

void print(data_t& a, int H, int W)
{
	std::stringstream ss;
	for (int h = 0; h < H; ++h)
	{
		for (int w = 0; w < W; ++w)
		{
			ss << a[h][w];
		}
		ss << std::endl;
	}

	std::cout << ss.str();
}

int main()
{
	int H, W;
	std::cin >> H >> W;

	data_t a;
	for (int h = 0; h < H; ++h)
		for (int w = 0; w < W; ++w)
		{
			std::cin >> a[h][w];
		}

	for (int h = 0; h < H; ++h)
	{
		if (isBlankRow(a, H, W, h))
		{
			deleteRow(a, H, W, h);
			--H;
			--h; //現在の行をもう一度チェックする
		}
	}

	for (int w = 0; w < W; ++w)
	{
		if (isBlankCol(a, H, W, w))
		{
			deleteCol(a, H, W, w);
			--W;
			--w; //現在の列をもう一度チェックする
		}
	}

	print(a, H, W);
	return 0;
}
