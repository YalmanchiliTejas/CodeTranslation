from collections import defaultdict
N, X, M = map(int, input().split())
A = [X]
visited = set()
visited.add(X)

idx = defaultdict()
idx[X] = 0

iii = -1

for i in range(1, M):
    tmp = (A[-1]**2) % M
    if tmp not in visited:
        A.append(tmp)
        visited.add(tmp)
        idx[tmp] = i
    else:
        iii = idx[tmp]

ans = 0
# ループの頭の直前まで
ans += sum(A[:iii])
N -= iii
if N > 0:
    # ループの長さ
    l = len(A) - iii
    ans += (N // l) * sum(A[iii:])
    N -= N // l * l
if N > 0:
    # ループに満たないN
    ans += sum(A[iii:iii + N])

print(ans)
exit()
