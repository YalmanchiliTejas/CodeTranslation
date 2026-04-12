import itertools

N,M = map(int, input().split())
E = [[0]*N for _ in range(N)]
for _ in range(M):
    y, x = map(int, input().split())
    E[y-1][x-1] = 1
    E[x-1][y-1] = 1

ans = 0
L = [int(i) for i in range(1, N)]
for P in itertools.permutations(L):
    f = 0
    for i in range(N-1):
        if i == 0:
            if E[0][P[i]] == 0:
                f = 1
                break
        elif E[P[i-1]][P[i]] == 0:
            f = 1
            break
    if f == 0:
        ans += 1
        
print(ans)