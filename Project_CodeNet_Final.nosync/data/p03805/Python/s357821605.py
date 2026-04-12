import itertools

N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(M)]

lis = [i for i in range(1, N+1)]
T = itertools.permutations(lis)

ans = 0

for t in T:
    if t[0] == 1:
        for i in range(N-1):
            A = [list(t)[i], list(t)[i+1]]
            B = [list(t)[i+1], list(t)[i]]
            if not (A in L or B in L):
                break
        else:
            ans += 1
print(ans)
