import itertools
n,m=map(int,input().split())
lst=[]
for i in range(m):
    lst+=[list(map(int,input().split()))]



pair=[[0]*n for i in range(n)]
for i,j in lst:
    pair[i-1][j-1]=1
    pair[j-1][i-1]=1


def keiro(a):
    count=0
    for i in range(n-1):
        if pair[a[i]-1][a[i+1]-1]==0:
            break
    else:
        count+=1
    return count
cn=0
b=[i for i in range(2,n+1)]
for i in list(itertools.permutations(b)):
    a=[1]+list(i)
    if keiro(a)==1:
        cn+=1

print(cn)