ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

s = input()
k = ii()

#dp[keta][not0nokosuu]
n = len(s)
dp = [[0]*(n) for _ in range(4)]
dp[0][0] = 1
for i in range(1,n):
    #のこり0のやつ
    dp[0][i] = dp[0][i-1] 
    #のこり1のやつ
    dp[1][i] = dp[0][i-1] * 9 + dp[1][i-1]
    #のこり2のやつ
    dp[2][i] = dp[1][i-1]*9 + dp[2][i-1]
    dp[3][i] = dp[2][i-1]*9 + dp[3][i-1]

ans = 0
for i in range(n):
    ima = int(s[i])
    if i ==-1 :
        ans += (ima -1) * dp[k-1][n-1-i]
        k -= 1
    else:
        if ima != 0:
            ans += (ima -1) * dp[k-1][n-1-i] + dp[k][n-1-i]
            k -= 1
    if k == 0:
        ans += 1
        break
print(ans)

