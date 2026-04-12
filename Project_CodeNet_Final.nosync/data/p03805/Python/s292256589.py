import itertools

N, M = map(int, input().split())
AB, ans = [tuple(map(int, input().split())) for _ in range(M)], 0

for p in itertools.permutations(range(1, N + 1)):
    if p[0] == 1:
        ans += 1
        for i in range(N - 1):
            if not (min(p[i], p[i + 1]), max(p[i], p[i + 1])) in AB:
                ans -= 1
                break

print(ans)
