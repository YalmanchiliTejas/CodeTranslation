from itertools import permutations
n,m=map(int,input().split())
lst=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    lst[a-1].append(b-1)
    lst[b-1].append(a-1)
kumi=list(permutations(range(1,n)))
ans=0
for i in kumi:
    switch=1
    prev=0
    for j in range(n-1):
        if not i[j] in lst[prev]:
            switch=0
            break
        prev=i[j]
    if switch==1:
        ans+=1
print(ans)