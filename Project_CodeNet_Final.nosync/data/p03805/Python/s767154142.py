import itertools

n,m = map(int,input().split())
li = [[0 for _ in range(n)] for _ in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    a-=1
    b-=1
    li[a][b] = 1
    li[b][a] = 1

num = [i for i in range(1,n)]
ans = 0


for v in itertools.permutations(num):
    bre = False
    if li[0][v[0]] == 0:
        continue
    for i in range(len(v)-1):
        if li[v[i]][v[i+1]] == 0:
            bre = True
            break
    if bre:
        continue
    else:
        ans += 1
print(ans)




