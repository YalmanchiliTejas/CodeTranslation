import itertools
N,M=map(int,input().split())
L=[[] for _ in range(N)]
for _ in range(M):
    a,b=map(int,input().split())
    L[a-1].append(b-1)
    L[b-1].append(a-1)
cnt=0
for i in itertools.permutations(range(N),N):
    if i[0]==0:
        for j in range(N):
            if j==N-1:
                cnt+=1
                break
            if not (i[j+1] in L[i[j]]):
                break
print(cnt)