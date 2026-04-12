import itertools

N, M = map(int, input().split())
ab = []
for _ in range(M):
    a, b = map(int, input().split())
    ab.append({a-1, b-1})

ans = 0
for v in itertools.permutations(range(1, N)):
    ok = True
    a = 0
    for b in v:
        if {a, b} not in ab:
            ok = False
            break
        a = b
    if ok:
        ans += 1

print(ans)
