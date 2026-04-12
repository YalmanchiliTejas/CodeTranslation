N = int(input())
K = int(input())
S = str(N)
'''
ans = 0
li = []
for i in range(1,N+1):
    if str(i).count('0') == len(str(i)) - K:
        ans += 1
        li.append(i)
print(ans)
print(li)
'''
L = len(S)

dp = [[[1, 0], [0, 0], [0, 0], [0, 0]] for i in range(L)]
dp[0] = [[1, 0], [int(S[0])-1, 1], [0, 0], [0, 0]]
#print(dp)
for l in range(1,L):
    s = int(S[l])
    if s == 0:
        dp[l][1][1] += dp[l-1][1][1]
        dp[l][2][1] += dp[l-1][2][1]
    else:
        dp[l][1][1] += dp[l-1][0][1]
        dp[l][2][1] += dp[l-1][1][1]
        dp[l][3][1] += dp[l-1][2][1]
        dp[l][1][0] += dp[l-1][1][1]
        dp[l][2][0] += dp[l-1][2][1]
        dp[l][3][0] += dp[l-1][3][1]

    dp[l][1][0] += dp[l-1][0][0]*9 + dp[l-1][1][0]
    dp[l][2][0] += dp[l-1][1][0]*9 + dp[l-1][2][0]
    dp[l][3][0] += dp[l-1][2][0]*9 + dp[l-1][3][0]
    dp[l][1][0] += dp[l-1][0][1]*max(0,s-1)
    dp[l][2][0] += dp[l-1][1][1]*max(0,s-1)
    dp[l][3][0] += dp[l-1][2][1]*max(0,s-1)

#print(dp)
print(sum(dp[L-1][K]))