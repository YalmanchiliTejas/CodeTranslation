import itertools
N,M = map(int,input().split())
r = []
for _ in range(M):
    add = list(map(int,input().split()))
    r.append(add)
    r.append(add[::-1])
A = [i for i in range(2,N + 1)]
A = list(itertools.permutations(A,N - 1))
ans = 0
for check in A:
    q = 0
    p = [1] + list(check)
    for c in range(N - 1):
        if p[c:c + 2] in r:
            q += 1
    if q == N - 1:
        ans += 1
print(ans)