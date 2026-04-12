import math

N,X,M = map(int, input().split())
MAP = [-1]*(M+1)
TMAP = [0]*(M+1)
ans = 0

for i in range(N):
    if (X%M!=0):
        X = X%M
        ans += X
        if MAP[X]==-1:
            MAP[X] = i
            TMAP[X] = ans
        else:
            loopcnt = i-MAP[X]
            loopsum = ans-TMAP[X]
            ans += (((N-MAP[X])//loopcnt)-1)*loopsum
            jmax = N-(MAP[X]+((N-MAP[X])//loopcnt)*loopcnt)
            ans -= X
            for j in range(jmax):
                X = X%M
                ans += X
                X = X**2
            X=M
        X = X**2
    else:
        break

print(ans)
