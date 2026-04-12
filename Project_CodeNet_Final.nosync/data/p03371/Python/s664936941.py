# 与えられた数値の桁数と桁値の総和を計算する.
def calc_digit_sum(num):
    digits = sums = 0
    while num > 0:
        digits += 1
        sums += num % 10
        num //= 10
    return digits, sums


a, b, c, x, y = map(int, input().split())

min_v = min(x, y)
max_v = max(x, y)

candidate1 = (a * x) + (b * y)
candidate2 = c * (max_v * 2)
candidate3 = c * (min_v * 2) + (a * (max_v - min_v) if max_v == x else b * (max_v - min_v))

print(min(candidate1, candidate2, candidate3))