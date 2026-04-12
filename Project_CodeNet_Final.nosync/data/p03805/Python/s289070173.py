from itertools import permutations
N, M = map(int, input().split())
AB = [list(map(int, input().split())) for i in range(M)]

# path候補を全列挙
route = [i for i in range(2, N+1)]
routes = list(permutations(route))
ans = 0

for route in routes:
    now = 1
    for r in route:
        if ([now, r] not in AB) and ([r, now] not in AB):
            now = r
            break
        now = r
    else:
        ans += 1

print(ans)