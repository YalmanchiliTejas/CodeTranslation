N, K = map(int, input().split())

if K == 0:
    print(N**2)
    exit()

ans = 0
for b in range(K+1, N+1):
    ans += (N//b)*(b-K)
    ans += max(0, N-((N//b)*b+K)+1)
    # print(b, ans)
print(ans)
