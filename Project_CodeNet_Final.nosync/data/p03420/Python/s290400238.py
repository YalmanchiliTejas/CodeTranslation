import sys
N, K = map(int, input().split())
if K == 0:
    print(N**2)
    sys.exit()
ans = 0
for b in range(K+1,N+1):
    peri, res = divmod(N,b)
    ans += (b-K)*peri + max(0,res-K+1)

print(ans)