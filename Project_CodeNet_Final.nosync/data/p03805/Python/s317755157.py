N,M=map(int,input().split());L=[[]for _ in range(N+1)]
for _ in range(M):a,b=map(int,input().split());L[a]+=[b];L[b]+=[a]
def s(n,v):
 if n in v:return 0
 if len(v)==N-1:return 1
 return sum(s(i,v|{n})for i in L[n])
print(s(1,set()))