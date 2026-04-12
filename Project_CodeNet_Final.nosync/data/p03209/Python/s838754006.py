import sys

sys.setrecursionlimit(10 ** 9)

get_length = []
for i in range(50 + 1):
    get_length.append(1 + 4 * (2 ** i - 1))

get_p = []
t = 0
for i in range(50 + 1):
    t = t * 2 + 1
    get_p.append(t)


def dfs(kk, ss, tt):
    if ss > tt:
        return 0

    if kk == 0:
        return 1

    target_length = get_length[kk]
    m = (1 + target_length) // 2

    if 1 <= ss <= 2 and target_length - 1 <= tt <= target_length:
        return get_p[kk]

    if ss == 1:
        return dfs(kk, 2, tt)

    if tt == target_length:
        return dfs(kk, ss, tt - 1)

    if ss == m:
        return 1 + dfs(kk, ss + 1, tt)

    if tt == m:
        return dfs(kk, ss, tt - 1) + 1

    if ss < m < tt:
        return dfs(kk, ss, m - 1) + 1 + dfs(kk, m + 1, tt)

    if ss < m:
        return dfs(kk - 1, ss - 1, tt - 1)
    else:  # ss > m
        return dfs(kk - 1, ss - m, tt - m)


n, x = map(int, input().split())
ans = 0
if get_length[n] < 2 * x:
    ans = get_p[n] - dfs(n, 1, get_length[n] - x)
else:
    ans = dfs(n, 1, x)
print(ans)
