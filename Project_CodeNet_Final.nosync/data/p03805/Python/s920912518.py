from itertools import permutations
n,m=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(m)]
MAP=[[] for _ in range(n)]
for a,b in AB:
    MAP[a-1].append(b-1)
    MAP[b-1].append(a-1)

ans=0
for A in permutations(range(n),n):
    if A[0]==0:
        for i in range(n):
            if i==n-1:
                ans +=1
                break
            if A[i+1] not in MAP[A[i]]:break
print(ans)