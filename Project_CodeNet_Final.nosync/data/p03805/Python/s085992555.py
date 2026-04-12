from itertools import permutations

N,M=map(int,input().split())
E=[[0]*(N+1) for _ in range(N+1)]

for _ in range(M):
    a,b=map(int,input().split())
    E[a][b]=1
    E[b][a]=1

P=permutations([x for x in range(2,N+1)])

K=0
for p in P:
    Q=[1]+list(p)

    F=1
    for k in range(N-1):
        F*=E[Q[k]][Q[k+1]]

    K+=F
print(K)
