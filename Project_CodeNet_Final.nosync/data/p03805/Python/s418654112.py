import itertools


n, m = map(int, input().split())
ab = []
for _ in range(m):
    ab.append(list(map(int, input().split())))

ans = 0
for p in itertools.permutations(range(1, n + 1)):
    if p[0] != 1:
        break

    for i in range(n - 1):
        for ai, bi in ab:
            if (p[i] == ai and p[i + 1] == bi
                    or p[i] == bi and p[i + 1] == ai):
                break
        else:
            break
    else:
        ans += 1

print(ans)