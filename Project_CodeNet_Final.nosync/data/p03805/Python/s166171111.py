import itertools
n,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(m)]
s=list(itertools.permutations(range(1,n+1)))
count=0
for lis in s:
    flag=False
    if lis[0]==1:
        if all([lis[i],lis[i+1]] in l or [lis[i+1],lis[i]] in l for i in range(n-1)):
            count+=1          
print(count)