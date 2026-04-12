import itertools
n,m = list(map(int,input().split()))
A = [list(map(int,input().split())) for _ in range(m)]
a = [0]*n
for x,y in A:
  a[x-1] |= 1<<(y-1)
  a[y-1] |= 1<<(x-1)

def bitdp(n, a):
  dp = [[0]*n for _ in range(1<<n)]
  dp[1][0] = 1
  
  for bit in range(1<<n):
    for v in range(n):
      if bit & 1<<v:
        sub = bit ^ (1<<v)
        
        for u in range(n):
          if (sub & 1<<u) and (a[v] & 1<<u):
            dp[bit][v] += dp[sub][u]
  ans = sum(dp[(1<<n)-1][u] for u in range(1,n))
  return ans

ans = bitdp(n,a)
print(ans)