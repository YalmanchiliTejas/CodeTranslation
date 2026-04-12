N,M = [int(i) for i in input().split()]
p = {}

for _ in range(M):
    a, b = map(int, input().split())
    if a in p:
        p[a].append(b)
    else:
        p[a] = [b]
    if b in p:
        p[b].append(a)
    else:
        p[b] = [a]

cnt = 0

def func(q,l,n):
    if n == N:
        global cnt
        cnt += 1
    for i in p[q]:
        if i not in l:
            func(i, l+[i], n+1)

func(1, [1], 1)
print(cnt)
