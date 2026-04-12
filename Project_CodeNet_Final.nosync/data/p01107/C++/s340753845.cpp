#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include <bitset>

enum class Direction {
	Right, Forward, Left, Backward
};
constexpr std::array<Direction, 4> Directions{ Direction::Right, Direction::Forward, Direction::Left, Direction::Backward };
enum class Bearing {
	North, East, South, West
};
Bearing change_direction(const Bearing b, const Direction d) {
	int bear{ 0 };
	switch (b) {
	case Bearing::North: ++bear;
	case Bearing::West: ++bear;
	case Bearing::South: ++bear;
	case Bearing::East: ++bear;
	default: bear %= 4;
	}
	int dir{ 0 };
	switch (d) {
	case Direction::Forward: ++dir;
	case Direction::Left: ++dir;
	case Direction::Backward: ++dir;
	case Direction::Right: ++dir;
	default: dir %= 4;
	}
	switch ((bear + dir) % 4) {
	case 0: return Bearing::North;
	case 1: return Bearing::East;
	case 2: return Bearing::South;
	case 3: return Bearing::West;
	default: throw 0;
	}
}
struct Coordinate {
	int x, y;
	bool operator==(const Coordinate that) const {
		return x == that.x && y == that.y;
	}
	bool operator!=(const Coordinate that) const {
		return !(*this == that);
	}
	Coordinate operator+(const Coordinate that) const {
		return Coordinate{ x + that.x, y + that.y };
	}
	Coordinate move(const Bearing bearing) const {
		switch (bearing) {
		case Bearing::North: return Coordinate{ x, y - 1 };
		case Bearing::East: return Coordinate{ x + 1, y };
		case Bearing::South: return Coordinate{ x, y + 1 };
		case Bearing::West: return Coordinate{ x - 1, y };
		default: throw 0;
		}
	}
};
struct State {
	Coordinate position;
	Bearing bearing;
	State move(const Bearing bearing) const {
		return State{ position.move(bearing), bearing };
	}
	State move(const Direction direction) const {
		return move(change_direction(bearing, direction));
	}
	bool operator!=(const State that) const {
		return position != that.position || bearing != that.bearing;
	}
};
State moved(const State current, const std::vector<std::string>& state) {
	for (const auto dir : Directions) {
		const auto next = current.move(dir);
		if (0 <= next.position.y && next.position.y < state.size() && 0 <= next.position.x && next.position.x < state[next.position.y].size() && state[next.position.y][next.position.x] != '#') {
			return next;
		}
	}
	return current;
}
std::stack<Coordinate> cal_route(const Coordinate from, const Coordinate to, const std::vector<std::string>& state) {
	State single_state{ from, Bearing::South };
	auto double_state = moved(single_state, state);
	std::stack<Coordinate> stack;
	while (single_state.position != to && single_state != double_state) {
		single_state = moved(single_state, state);
		double_state = moved(moved(double_state, state), state);
		stack.push(single_state.position);
	}
	if (single_state.position == to) {
		return stack;
	}
	else {
		return std::stack<Coordinate>();
	}
}
int main() {
	while (true) {
		int height, width; std::cin >> height >> width; if (height == 0) break;
		std::vector<std::string> state(height); for (auto& line : state) std::cin >> line;
		std::vector<Coordinate> targets{ Coordinate{0, 0}, Coordinate{0, height - 1}, Coordinate{width - 1, height - 1}, Coordinate{width - 1, 0} };
		bool can_make = true;
		for (auto i = 0; i < 4; ++i) {
			auto route = cal_route(targets[i], targets[(i + 1) % 4], state);
			if (route.empty()) {
				can_make = false;
				break;
			}
			else {
				while (!route.empty()) {
					state[route.top().y][route.top().x] = '#';
					route.pop();
				}
			}
		}
		if (can_make) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
}
