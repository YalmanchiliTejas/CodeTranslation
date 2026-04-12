N, K = map(int,input().split())
ans = 0
for a in range(1,N+1):
    ans += max(0,a-K)*(N//a)+max(0,N%a-K+1)
if K == 0:
    ans -= N
print(ans)
