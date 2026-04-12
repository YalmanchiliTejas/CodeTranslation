N, X = map(int, input().split())
layer_n = [0] * (N+1)
P_n = [0] * (N+1)
layer_n[0] = 1
P_n[0] = 1
for i in range(1,N+1):
    layer_n[i] = layer_n[i-1]*2 + 3
    P_n[i] = P_n[i-1]*2 + 1

def solve(n,x,ans):
    if x == 0:
        return ans
    if n == 0:
        return ans + 1
    mid = layer_n[n]//2 + 1
    if x < mid:
        return solve(n-1,x-1,ans)
    elif x == mid:
        return ans + P_n[n-1]+1
    else:
        x -= 2 + layer_n[n-1]
        ans += P_n[n-1]+1
        return solve(n-1,x,ans)

print(solve(N,X,0))
