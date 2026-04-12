n = input()
k = int(input())
l = len(n)

dp = [[[0 for a in range(k+1)] for b in range(2)] for c in range(l+5)]

dp[0][0][0] = 1
#print(dp)

for a in range(l) :
    for b in range(2) :
        for c in range(k+1) :
            for d in range(10) :
                na = a
                nb = b
                nc = c
                if b == 0 :
                    if d > int(n[a]) :
                        continue
                    if d < int(n[a]) :
                        nb = 1
                if c == k and d > 0 :
                    continue
                if d != 0 :
                    nc += 1
                #print(a,b,c,na,nb,nc)
                dp[na+1][nb][nc] += dp[a][b][c]

#print(dp[l][0][k])
#print(dp[l][1][k])
print(dp[l][0][k]+dp[l][1][k])
