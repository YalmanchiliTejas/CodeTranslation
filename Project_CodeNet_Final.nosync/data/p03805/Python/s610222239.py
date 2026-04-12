from itertools import permutations
n,m=map(int,input().split())

M=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    M[a-1].append(b-1)
    M[b-1].append(a-1)

ans=0
for A in permutations(range(n),n):
    if A[0]==0:
        for i in range(n):
            if i==n-1:
                ans +=1
                break
            if A[i+1] not in M[A[i]]:break

print(ans)