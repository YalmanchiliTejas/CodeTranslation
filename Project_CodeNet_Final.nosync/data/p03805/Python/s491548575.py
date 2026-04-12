import itertools

n,m = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(m)]
pair = [[] for _ in range(n+1)]
for i in range(m):
    a = A[i][0]
    b = A[i][1]
    pair[a].append(b)
    pair[b].append(a)

ans = 0
li = [i for i in range(2,n+1)]
orders = list(itertools.permutations(li))

for order in orders:
    flag = True
    pre = 1
    for i in range(n-1):
        if not order[i] in pair[pre]:
            flag = False
        pre = order[i]
    if flag:
        ans += 1
print(ans)