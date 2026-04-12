N, K = map(int, input().split())
ans = 0

for b in range(1, N+1):
    if K>=b:
        continue
    
    if K==0:
        ans += N
    else:
        ans += N//b*(b-K)+max(N%b-K+1, 0)

print(ans)