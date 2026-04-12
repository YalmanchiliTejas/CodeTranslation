import itertools
n,m = map(int,input().split())

a = [[] for i in range(n)]
for i in range(m):
    b = list(map(int,input().split()))
    a[b[0]-1].append(b[1]-1)
    a[b[1]-1].append(b[0]-1)

#print(a)

c = list(itertools.permutations(range(1, n)))
len_c = len(c)

#print(c)
ans = 0
for i in range(len_c):
    now = 0
    check = True
    for j in range(n - 1):
        if not c[i][j] in a[now]:
            check = False
        now = c[i][j]
    if check:
        ans += 1

print(ans)