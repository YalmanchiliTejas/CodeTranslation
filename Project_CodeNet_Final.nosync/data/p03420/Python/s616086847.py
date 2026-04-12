N,K = map(int,input().split())
if K == 0:
    print(N*N)
    exit()

ans = 0
for b in range(1,N+1):
    cycle,rem = divmod(N,b)
    ans += cycle * max(0, b-K)
    ans += max(0, rem+1 - K)
print(ans)