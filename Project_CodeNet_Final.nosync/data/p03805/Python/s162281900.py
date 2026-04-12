import itertools
n,m = map(int,input().split())
vert = [[0] for i in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    vert[a].append(b)
    vert[b].append(a)
parents = [0]
now = 1
ans = 0
for i in list(itertools.permutations(range(1,n+1))):
    if i[0] == 1:
        for j in range(1,n):
            if i[j] not in vert[i[j-1]]:
                break
        else:
            ans += 1
print(ans)