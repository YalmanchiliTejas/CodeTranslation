N,X = (int(x) for x in input().split())
P = [1]
for i in range(N):
    P.append(1+2*(P[-1]))
PB = [1]
for i in range(N):
    PB.append(3+2*(PB[-1]))
ans = 0
for i in range(N+1):
    if X == PB[N-i]:
        if N - i > 0:
            ans += 1 + (2*P[N-1-i])
            break
        else:
            ans += 1
            break
    elif X == 2 + PB[N-1-i]:
        ans += 1 + P[N-1-i]
        break
    elif X == 1:
        break
    elif X < 2 + PB[N-1-i]:
        X -= 1
    else:
        X -= 2 + PB[N-1-i]
        ans += 1 + P[N-1-i]
print(ans)