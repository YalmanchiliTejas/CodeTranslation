from itertools import permutations

N, M = map(int, input().split())
E = [set() for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    E[a-1].add(b-1)
    E[b-1].add(a-1)

ans = 0
for p in permutations([i for i in range(1, N)]):
    i = 0
    for j in p:
        if j not in E[i]:
            break
        i = j
    else:
        ans += 1
print(ans)