import itertools
N, M = map(int, input().split())
A = [set(map(int, input().split())) for _ in range(M)]
ans = 0
for p in itertools.permutations(range(2, N+1)):
    q = list(p) + [1]
    for i in range(N-1):
        if not {q[i], q[i+1]} in A:
            break
    else:
        ans += 1
print(ans)