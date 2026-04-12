from itertools import permutations

N, M = map(int, input().split())
E = []
for _ in range(M):
    a, b = map(int, input().split())
    E.append((a, b))
    E.append((b, a))
ans = 0
for p in permutations(range(2, N+1)):
    perm = [1] + list(p)
    for i in range(N-1):
        if (perm[i], perm[i+1]) not in E:
            break
    else:
        ans += 1
print(ans)