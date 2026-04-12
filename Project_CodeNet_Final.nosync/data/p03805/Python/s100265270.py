import sys
import itertools
n,m=map(int,input().split())
ab=[]
for _ in range(m):
    ab.append(list(map(int,input().split())))

lis=list(range(1,n+1))
per_lis = itertools.permutations(lis) 

ans=0

for one_case in per_lis:
    if one_case[0]==1:
        tmp=0
        for j in range(n-1):
            for num in ab:
                if one_case[j]==num[0] and one_case[j+1]==num[1]:
                    tmp+=1
                elif one_case[j]==num[1] and one_case[j+1]==num[0]:
                    tmp+=1
                    

        if tmp==n-1:
            ans+=1

print(ans)