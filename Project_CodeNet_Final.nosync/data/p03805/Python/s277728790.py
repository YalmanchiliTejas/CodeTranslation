import itertools as it
import sys

N, M = map(int, input().split())
if N==0 or M==0:
    print(0)
    sys.exit()
a=[]

for i in range(M):
    x,y=map(int,input().split())
    a.append([x,y])
    a.append([y,x])

ans=0
for e in it.permutations(range(N)):
    if e[0]!=0:
        break
        
    count=1
    for j in range(N-1):
        if [e[j]+1,e[j+1]+1] in a:
            count*=1
        else:
            count*=0
            break
            
    ans+=count

print(ans)