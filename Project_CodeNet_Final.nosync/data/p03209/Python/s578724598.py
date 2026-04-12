N,X = map(int,input().split())

l1 = 'BPPPB'

L = [1]
for i in range(1,51):
    L.append(L[i-1]*2+3)

dp = [-1]*51

def solve(n, x):
    if n == 0:
        return 1
    l_num = L[n]
    temp = 0
    if dp[n-1]==-1:
        temp = solve(n-1, L[n-1])
        dp[n-1] = temp
    else:
        temp = dp[n-1]

    if x == l_num//2+1:
        return temp+1
    elif n < x < l_num//2+1:
        return solve(n-1, x-1)
    elif x > l_num//2+1:
        # if n==3:
        #     print(x-l_num//2)
        return temp+1 +\
                solve(n-1, x-l_num//2-1)
    elif x <= n:
        return 0

print(solve(N,X))
