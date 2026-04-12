import sys
input = sys.stdin.readline
 
N, X = [int(x) for x in input().split()]
# P,B
L = [1]

#P
P = [1]

for i in range(N):
    L.append(3 + L[-1] * 2)
    P.append(1 + P[-1] * 2)

ans = 0
# idx = N
while True:
    if L[N] == X:
        ans += P[N]
        print(ans)
        break
    elif L[N] - 1 == X:
        ans += P[N]
        print(ans)
        break
    elif 2 + L[N - 1] <= X:
        ans += 1 + P[N - 1]
        X -= 2 + L[N - 1]
        if X == 0:
            print(ans)
            break
    elif 1 + L[N - 1] == X:
        ans += P[N - 1]
        print(ans)
        break
    elif X == 1:
        print(ans)
        break
    else:
        X -= 1
    N -= 1 






