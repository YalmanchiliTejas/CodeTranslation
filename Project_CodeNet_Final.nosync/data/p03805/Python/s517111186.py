N,M=map(int,input().split())
s=[[]for i in range(N)]
w=0
for i in range(M):
    x,y=map(int,input().split())
    x,y=x-1,y-1
    s[x].append(y)
    s[y].append(x)
from itertools import permutations
for j in permutations(range(1,N)):
    j=[0]+list(j)
    for k in range(1,N):
        if j[k] not in s[j[k-1]]:
            break
    else:
        w+=1
print(w)            
        
        
