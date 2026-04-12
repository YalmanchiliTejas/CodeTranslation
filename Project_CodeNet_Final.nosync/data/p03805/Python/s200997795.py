import itertools as it

n,m=map(int,input().split())
path=[]
for i in range(m): path.append(list(map(int,input().split())))
ls=list(it.permutations(range(1,n+1)))
cnt=0
for l in ls:
    if l[0]!=1: break
    flag=1
    for i in range(n-1):
        if ([l[i],l[i+1]] not in path) and ([l[i+1],l[i]] not in path):
            flag=0
            break
    if flag: cnt+=1
print(cnt)