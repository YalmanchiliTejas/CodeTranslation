N, K = map(int, input().split())
if K==0:
    print(N**2)
    exit()
res = 0
for b in range(1,N+1):
    res += (N//b)*max(b-K,0) + max(N%b-K+1, 0)
print(res)