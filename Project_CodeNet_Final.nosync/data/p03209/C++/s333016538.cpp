#include <bits/stdc++.h>

using namespace std;

constexpr int64_t layerCounts[51] = {
    INT64_C(1),
    INT64_C(5),
    INT64_C(13),
    INT64_C(29),
    INT64_C(61),
    INT64_C(125),
    INT64_C(253),
    INT64_C(509),
    INT64_C(1021),
    INT64_C(2045),
    INT64_C(4093),
    INT64_C(8189),
    INT64_C(16381),
    INT64_C(32765),
    INT64_C(65533),
    INT64_C(131069),
    INT64_C(262141),
    INT64_C(524285),
    INT64_C(1048573),
    INT64_C(2097149),
    INT64_C(4194301),
    INT64_C(8388605),
    INT64_C(16777213),
    INT64_C(33554429),
    INT64_C(67108861),
    INT64_C(134217725),
    INT64_C(268435453),
    INT64_C(536870909),
    INT64_C(1073741821),
    INT64_C(2147483645),
    INT64_C(4294967293),
    INT64_C(8589934589),
    INT64_C(17179869181),
    INT64_C(34359738365),
    INT64_C(68719476733),
    INT64_C(137438953469),
    INT64_C(274877906941),
    INT64_C(549755813885),
    INT64_C(1099511627773),
    INT64_C(2199023255549),
    INT64_C(4398046511101),
    INT64_C(8796093022205),
    INT64_C(17592186044413),
    INT64_C(35184372088829),
    INT64_C(70368744177661),
    INT64_C(140737488355325),
    INT64_C(281474976710653),
    INT64_C(562949953421309),
    INT64_C(1125899906842621),
    INT64_C(2251799813685245),
    INT64_C(4503599627370493),
};

constexpr int64_t pattyCounts[51] = {INT64_C(1),
                                     INT64_C(3),
                                     INT64_C(7),
                                     INT64_C(15),
                                     INT64_C(31),
                                     INT64_C(63),
                                     INT64_C(127),
                                     INT64_C(255),
                                     INT64_C(511),
                                     INT64_C(1023),
                                     INT64_C(2047),
                                     INT64_C(4095),
                                     INT64_C(8191),
                                     INT64_C(16383),
                                     INT64_C(32767),
                                     INT64_C(65535),
                                     INT64_C(131071),
                                     INT64_C(262143),
                                     INT64_C(524287),
                                     INT64_C(1048575),
                                     INT64_C(2097151),
                                     INT64_C(4194303),
                                     INT64_C(8388607),
                                     INT64_C(16777215),
                                     INT64_C(33554431),
                                     INT64_C(67108863),
                                     INT64_C(134217727),
                                     INT64_C(268435455),
                                     INT64_C(536870911),
                                     INT64_C(1073741823),
                                     INT64_C(2147483647),
                                     INT64_C(4294967295),
                                     INT64_C(8589934591),
                                     INT64_C(17179869183),
                                     INT64_C(34359738367),
                                     INT64_C(68719476735),
                                     INT64_C(137438953471),
                                     INT64_C(274877906943),
                                     INT64_C(549755813887),
                                     INT64_C(1099511627775),
                                     INT64_C(2199023255551),
                                     INT64_C(4398046511103),
                                     INT64_C(8796093022207),
                                     INT64_C(17592186044415),
                                     INT64_C(35184372088831),
                                     INT64_C(70368744177663),
                                     INT64_C(140737488355327),
                                     INT64_C(281474976710655),
                                     INT64_C(562949953421311),
                                     INT64_C(1125899906842623),
                                     INT64_C(2251799813685247)};

int64_t solve(int64_t n, int64_t x) {
  if (x <= n) {
    return 0;
  }
  int64_t const layerCount = layerCounts[n];
  int64_t const pattyCount = pattyCounts[n];
  if (layerCount - n <= x) {
    return pattyCount;
  }
  if (x <= layerCount / 2) {
    return solve(n - 1, x - 1);
  }
  if (x == layerCount / 2 + 1) {
    return solve(n - 1, x - 1) + 1;
  }
  return solve(n - 1, x - 1) + 1 + solve(n - 1, x - layerCount / 2 - 1);
}

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int64_t n, x;
  std::cin >> n >> x;
  std::cout << solve(n, x) << std::endl;
  return 0;
}
