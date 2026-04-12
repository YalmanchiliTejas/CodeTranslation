# A - Restaurant
# https://atcoder.jp/contests/abc055/tasks/abc055_a

N = int(input())

result = 0

result += 800 * N
result -= 200 * int(N / 15)

print(result)
