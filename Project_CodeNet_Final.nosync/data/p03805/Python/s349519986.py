import itertools

n, m = map(int, input().split())

ls = [[] for _ in range(n)]

for _ in range(m):
    s, t = map(int, input().split())
    ls[s-1].append(t-1)
    ls[t-1].append(s-1)

count = 0
for per in itertools.permutations(range(n)):

    if per[0] != 0:
        continue
    for i in range(1, n):
        if per[i] not in ls[per[i-1]]:
            break
        if i == n-1:
            count += 1

print(count)
