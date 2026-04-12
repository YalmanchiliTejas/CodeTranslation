import sys
import math

input = sys.stdin.readline
n = int(input())
k = int(input())
t = n
m = 0
while t:
    m += 1
    t //= 10

def comb(n, r):
    if r > n:
        return 0
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

ans = 9 ** k * comb(m-1, k)
tk = k

def dfs(i, mt, kt):
    a = i // 10 ** mt
    b = n // 10 ** mt
    if kt < 0:
        return 0
    if mt < kt:
        return 0
    if a < b:
        if mt > 0:
            return 9 ** kt * comb(mt, kt)
        else:
            return 1
    elif a > b:
        return 0
    if i == n and kt == 0:
        return 1
    elif i > n:
        return 0
    ret = 0
    for j in range(10):
        f = 0
        if j != 0:
            f = 1
        ret += dfs(i+j*10**(mt-1), mt-1, kt-f)
    return ret

t_ans = 0
for i in range(1, n // (10 ** (m-1) )+1):
    ti = i * 10 ** (m-1)
    t_ans += dfs(ti, m-1, k-1)

print(int(ans+t_ans))
