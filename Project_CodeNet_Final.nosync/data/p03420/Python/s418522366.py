import sys
N, K = [int(i) for i in input().split()]

if K == 0:
    print(N**2)
    sys.exit()

ans = 0
for b in range(K,N+1):
    ans += N//b*(b-K) + max(0, N%b -K+1)
print(ans)