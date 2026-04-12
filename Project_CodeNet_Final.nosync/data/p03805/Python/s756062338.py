import itertools

n, m = map(int, input().split())
relation = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    relation[a].append(b)
    relation[b].append(a)

ans = 0
for li in itertools.permutations(range(n), n):
    if li[0] == 0:
        for i in range(n-1):
            if not li[i + 1] in relation[li[i]]:
                break
        else:
            ans += 1

print(ans)
