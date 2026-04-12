import itertools
n,m=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(m)]
p=list(itertools.permutations(list(range(2,n+1))))
ans=0
for i in p:
    tmp=1
    for j in range(n-1):
        if [tmp,i[j]] in l or [i[j],tmp] in l:
            tmp=i[j]
        else:break
        if j==n-2:ans+=1
print(ans)