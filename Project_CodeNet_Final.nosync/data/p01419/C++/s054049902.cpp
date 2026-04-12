#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>

struct Room {
	int x, y;
	std::vector<Room> neighbors() const {
		return std::vector<Room>{ Room{x + 1, y}, Room{x - 1, y}, Room{x, y + 1}, Room{x, y - 1} };
	}
	bool operator==(const Room that) const { return x == that.x && y == that.y; }
	bool operator!=(const Room that) const { return !((*this) == that); }
};
bool set_next_room(const Room current, std::vector<std::vector<Room>>& next_room, std::vector<std::vector<int>> &searching, const std::vector<std::string> &office, const Room goal, const int current_step) {
	if (current == goal) return true;
	if (searching[current.y][current.x] == current_step) return false;
	searching[current.y][current.x] = current_step;
	for (const auto next : current.neighbors()) if (0 <= next.y && next.y < office.size() && 0 <= next.x && next.x < office[next.y].size() && office[next.y][next.x] != '#'){
		if (set_next_room(next, next_room, searching, office, goal, current_step)) {
			next_room[current.y][current.x] = next;
			return true;
		}
	}
	return false;
}
struct Light {
	int hold, on, off;
};
int main() {
	int r, c, m; std::cin >> r >> c >> m;
	std::vector<std::string> office(r); for (auto& o : office) std::cin >> o;
	std::vector<std::vector<Room>> next_room(r, std::vector<Room>(c));
	std::vector<std::vector<int>> searching(r, std::vector<int>(c, -1));
	std::vector<std::vector<std::vector<int>>> visit_timing(r, std::vector<std::vector<int>>(c));
	std::vector<std::vector<Light>> lights(r, std::vector<Light>(c));
	for (auto ri = 0; ri < r; ++ri) for (auto ci = 0; ci < c; ++ci) {
		std::cin >> lights[ri][ci].hold;
	}
	for (auto ri = 0; ri < r; ++ri) for (auto ci = 0; ci < c; ++ci) {
		std::cin >> lights[ri][ci].on;
	}
	for (auto ri = 0; ri < r; ++ri) for (auto ci = 0; ci < c; ++ci) {
		std::cin >> lights[ri][ci].off;
	}
	int current_time = 0;
	Room current; std::cin >> current.y >> current.x;
	visit_timing[current.y][current.x].push_back(0);
	for (auto i = 1; i < m; ++i) {
		Room dist; std::cin >> dist.y >> dist.x;
		set_next_room(current, next_room, searching, office, dist, i);
		while (current != dist) {
			current = next_room[current.y][current.x];
			visit_timing[current.y][current.x].push_back(++current_time);
		}
	}
	int sum_cost = 0;
	for (auto ri = 0; ri < r; ++ri) for (auto ci = 0; ci < c; ++ci) {
		sum_cost += visit_timing[ri][ci].size() * (lights[ri][ci].on + lights[ri][ci].off);
		for (auto i = 1; i < visit_timing[ri][ci].size(); ++i) {
			auto time = visit_timing[ri][ci][i] - visit_timing[ri][ci][i - 1];
			if (lights[ri][ci].hold * time < lights[ri][ci].on + lights[ri][ci].off) {
				sum_cost += lights[ri][ci].hold * time - lights[ri][ci].on - lights[ri][ci].off;
			}
		}
	}
	std::cout << sum_cost << '\n';
}
