N,M=map(int,input().split())
MAP=[[] for i in range(N+1)]
for i in range(M):
    a,b=map(int,input().split())
    MAP[a].append(b)
    MAP[b].append(a)

import itertools
T=[i+2 for i in range(N-1)]
PMT=list(itertools.permutations(T))
#print(MAP)
#print(PMT)

ans=0
for i in range(len(PMT)):
    t=[1]+list(PMT[i])
    flag=True
    for j in range(N-1):
        if t[j+1] not in MAP[t[j]]:
            flag=False
            break
    if flag:
        #print(t)
        ans+=1

print(ans)