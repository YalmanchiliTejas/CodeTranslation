N,X,M = map(int,input().split())
id = [-1] * M
lis = []
tot = 0
le = 0
while id[X] == -1:
    id[X] = le
    le += 1
    lis.append(X)
    tot += X
    X = (X**2) % M

c = le - id[X]
sm = 0
for i in range(id[X],le):
    sm += lis[i]
if (N <= le):
    ans = 0
    for i in range(N):
        ans += lis[i]
    print(ans)
    exit()

ans = tot
N -= le
ans += N // c * sm
N %= c
for i in range(id[X],id[X]+N):
    ans += lis[i]
print(ans)
