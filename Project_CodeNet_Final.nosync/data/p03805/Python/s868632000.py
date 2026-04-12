from itertools import permutations
import copy

def resolve():
    N, M = list(map(int, input().split()))
    G = [[0] * N for _ in range(N)]
    for i in range(M):
        a, b = list(map(int, input().split()))
        G[a-1][b-1] = 1
        G[b-1][a-1] = 1

    ls = list(permutations(range(1, N)))
    ans = 0
    for l in ls:
        h = copy.deepcopy(G)
        cnt = 1
        p = 0 
        for k in l:
            if h[p][k] == 0:
                break
            else:
                cnt += 1
                p = k
        if cnt == N:
            ans += 1
    print(ans)
    return

resolve()