import sys
sys.setrecursionlimit(10000000)

n, x = map(int, input().split())

num = [0] * (n + 1)
num_p = [0] * (n + 1)
num_h = [0] * (n + 1)
num[0] = 1
num_p[0] = 1

for i in range(1, n + 1):
    num[i] = num[i - 1] * 2 + 3
    num_p[i] = num_p[i - 1] * 2 + 1

for i in range(n + 1):
    num_h[i] = num[i] // 2 + 1

# idx 番目までに含むPの数を返す
def func(idx, n):
    if idx == 1 and n == 0:
        return 1
    if idx == 1 and n == 1:
        return 0
    if idx <= n or n < 0:
        return 0

    if idx == num_h[n]:
        ret = num_p[n - 1] + 1

    elif idx > num_h[n]:
        ret = num_p[n] - func(num[n] - idx - 1, n - 1)

    elif idx < num_h[n]:
        ret = func(idx - 1, n - 1)

    return ret

print(func(x, n))