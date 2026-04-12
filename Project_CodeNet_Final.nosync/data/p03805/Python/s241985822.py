from itertools import permutations

n,m = map(int,input().split())
ans = 0
dp = list([ 0 for i in range(n)] for _ in range(n))

for _ in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    dp[a][b] = 1
    dp[b][a] = 1

l = [i for i in range(1,n)]
for j in permutations(l):
    bit = 1
    if dp[0][j[0]]!=1:
        bit = 0
    for i in range(n-2):
        if dp[j[i]][j[i+1]]!= 1:
            bit = 0
    if bit==1:
        ans += 1
print(ans)