import itertools
N, M = map(int, input().split())
e = set([])
for i in range(M):
    a, b = map(int, input().split())
    e.add((a, b))
ans = 0
for i in list(itertools.permutations(range(2, N + 1))):
    a = 1
    for b in i:
        if (a, b) in e or (b, a) in e:
            a = b
            continue
        break
    else:
        ans += 1
print(ans)
