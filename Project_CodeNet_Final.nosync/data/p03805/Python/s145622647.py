import itertools
n,m=map(int,input().split())
e=[set() for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    e[a].add(b)
    e[b].add(a)
count=0
for i in itertools.permutations(range(2,n+1)):
    if i[0] not in e[1]:
        continue
    f=True
    for j in range(n-2):
        if i[j+1] not in e[i[j]]:
            f=False
            break
    if f:
        count+=1
print(count)