N,M=map(int,input().split())
AB=[list(map(int,input().split())) for i in range(M)]
c=[[0]*N for i in range(N)]
for a,b in AB:
    c[a-1][b-1]=c[b-1][a-1]=1
from itertools import permutations
r=0
for n in permutations(range(1,N)):
    n=[0]+list(n)
    x=1
    for i in range(N-1):
        if not c[n[i]][n[i+1]]:
            x=0
    r+=x
print(r)