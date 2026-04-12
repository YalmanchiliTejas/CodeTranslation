import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))

a.append(n+1)
a.append(n+1)

dp = [[-1]*(n+2) for i in range(n+2)]
ma = [-1]*(n+2)

dp[a[0]][a[1]] = 0
ma[a[0]] = 0
ma[a[1]] = 0

after = 0

for i in range(n):
    x,y,z = a[3*i+2],a[3*i+3],a[3*i+4]
    if x == z:
        y,z = z,y
    if y == z:
        x,z = z,x
    
    if x == z:
        after += 1
        continue

    
    tank = []

    if x != y:
        for i in range(n+1):
            tank.append((i,x,ma[i]))
            tank.append((i,y,ma[i]))
            tank.append((i,z,ma[i]))       
        tank.append((x,y,max(max(ma),dp[z][z] + 1)))
        tank.append((x,z,max(max(ma),dp[y][y] + 1)))
        tank.append((y,z,max(max(ma),dp[x][x] + 1)))
    else:
        for i in range(n+1):
            tank.append((i,x,ma[i]))
            tank.append((i,y,ma[i]))
            tmp = ma[i]
            if dp[i][x] != -1:
                tmp = max(tmp,dp[i][x] + 1)
            if dp[x][i] != -1:
                tmp = max(tmp,dp[x][i] + 1)
            tank.append((i,z,tmp))
        tank.append((x,y,max(max(ma),dp[z][z] + 1)))
        tank.append((x,z,max(max(ma),dp[y][y] + 1)))
        tank.append((y,z,max(max(ma),dp[x][x] + 1)))

    for p,q,c in tank:
        dp[p][q] = max(dp[p][q],c)
        ma[p] = max(ma[p],c)
        ma[q] = max(ma[q],c)

res = 0
for i in range(n+2):
    for j in range(n+2):
        res = max(res,dp[i][j])

print(res+after)