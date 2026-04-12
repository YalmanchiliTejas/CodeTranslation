# AtCoder Beginner Contest 095
# C - Half and Half
# https://atcoder.jp/contests/abc095/tasks/arc096_a

a, b, c, x, y = map(int, input().split())
mincost = 10**12

for i in range(x+y):
    cost = 2*c*i + a*max(0, x-i) + b*max(0, y-i)
    if cost < mincost:
        mincost = cost

print(mincost)
