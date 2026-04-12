N, X, M = map(int, input().split())
cur = X
pos = {}
path = []
i = 0
while cur not in pos:
    pos[cur] = i
    path.append(cur)
    cur = cur ** 2 % M
    i += 1

loop_start = pos[cur]
ans = None
if N <= len(path):
    ans = sum(path[:N])
else:
    ans = sum(path)
    left = N - len(path)
    q, r = divmod(left, len(path) - loop_start)
    ans += q * sum(path[loop_start:]) + sum(path[loop_start:loop_start + r])
print(ans)