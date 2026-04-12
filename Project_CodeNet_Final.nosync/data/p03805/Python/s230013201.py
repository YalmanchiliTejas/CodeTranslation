import itertools
N, M = map(int, input().split())
X = [[int(a) - 1 for a in input().split()] for _ in range(M)]
Y = [[0] * N for _ in range(N)]
for a, b in X:
    Y[a][b] = 1
    Y[b][a] = 1
ans = 0
for A in itertools.permutations(range(1, N)):
    A = [0] + [a for a in A]
    if all([Y[A[i]][A[i+1]] for i in range(N-1)]):
        ans += 1
print(ans)