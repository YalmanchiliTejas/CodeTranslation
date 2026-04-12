N,K = map(int,input().split())
ans = 0
if K == 0:
    print(N**2)
    exit()
for b in range(K+1,N+1):
    p = N // b
    r = N % b
    ans += p*(b-K)+max(0,r-K+1)

print(ans)