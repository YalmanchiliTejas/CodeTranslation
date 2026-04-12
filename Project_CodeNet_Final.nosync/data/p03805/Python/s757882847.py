import itertools
n, m = map(int, input().split())
to = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    to[a-1].append(b-1)
    to[b-1].append(a-1)

count = 0
seq = list(range(1,n))
permutation = itertools.permutations(seq)
for l in permutation:
    t = 0
    flag = 0
    for i in l:
        c = to[i].count(t)
        if c == 0:
            flag = 1
            break
        t = i
    if flag == 0:
        count += 1
    flag = 0

print(count)