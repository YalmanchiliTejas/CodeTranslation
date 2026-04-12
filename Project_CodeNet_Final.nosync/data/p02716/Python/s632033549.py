# F - Select Half

n = int(input())
a = list(map(int, input().split()))
assert len(a) == n

l = [0] * n # a[0]〜a[i]からfloor((i+1)/2)個選ぶときの最大値
u = [0] * n # a[0]〜a[i]からceil((i+1)/2)個選ぶときの最大値

l[0] = 0
u[0] = a[0]
u[1] = max(a[:2])
l[1] = u[1]

# 0 1 2 3 4 5 6 7 8 9 10 i
# . . . . . . . . . . .
# 1 1 2 2 3 3 4 4 5 5 6  u[i]
# 0   1   2   3   4   5  l[i]

for i in range(2, n):
    l[i] = max(u[i - 1], l[i - 2] + a[i])
    u[i] = u[i - 2] + a[i]
    if i % 2 != 0:
        u[i] = max(u[i - 1], u[i])

print(l[-1])
