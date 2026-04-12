
N, X, M = map(int, input().split())
dp = [False]*(M+1)
dp[X] = True
S = [0]*(M+1)
S[1] = X
tmp = X
for i in range(2, min(M+1, N+1)):
    tmp = pow(tmp, 2, M)
    if dp[tmp]:
        for j in range(1, i):
            if tmp == S[j]:
                break
        ans = 0
        for k in range(j, i):
            ans += S[k]
        ans *= (N-j+1)//(i-j)
        for k in range(1, j):
            ans += S[k]
        for k in range(j, j+(N-j+1)%(i-j)):
            ans += S[k]
        print(ans)
        break
    else:
        dp[tmp] = True
        S[i] = tmp
else:
    print(sum(S))