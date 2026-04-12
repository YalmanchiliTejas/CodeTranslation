N, K = map(int, input().split())
ans = 0
if K == 0:
    print(N**2)
    exit()
    
for b in range(1, N+1):
    block_K = max(0, b-K)
    #print("b", b, "block_num", (N+1)//b, "block_K", block_K, "remain", (N+1)%b)
    ans += block_K * ((N+1)//b) + max(0, (N+1)%b - K)

print(ans)