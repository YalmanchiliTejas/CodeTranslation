n,m=map(int,input().split())
a=[[] for i in range(n)]
for i in range(m):
    x,y=map(int,input().split())
    a[x-1].append(y-1)
    a[y-1].append(x-1)

import itertools
p=itertools.permutations(range(1,n))
p=list(p)

def check(x,y):
    if y in a[x]:
        return True
    else:
        return False
ans=0
for route in p:
    flag=True
    for i in range(n-1):
        if i==0:
            if check(0,route[i])==True:
                pass
            else:
                flag=False
        else:
            if check(route[i-1],route[i])==True:
                pass
            else:
                flag=False
    if flag==True:
        ans+=1
print(ans)
