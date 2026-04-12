# D - Christmas
import sys
sys.setrecursionlimit(10**7)

N, X = map(int, input().split())

burger = [[0, 0] for _ in range(N)]
burger[0] = [1, 1]

for i in range(1, N):
    burger[i][0] = burger[i-1][0] * 2 + 3
    burger[i][1] = burger[i-1][1] * 2 + 1

ans = 0
while True:
    if N == 0:
        if X > 0:
            ans += 1
        break
    if X > burger[N-1][0]+2:
        ans += burger[N-1][1] + 1
        X -= burger[N-1][0]+2
        N -= 1
    elif X == burger[N-1][0]+2:
        ans += burger[N-1][1] + 1
        break
    elif X < burger[N-1][0]+2:
        X -= 1
        N -= 1
print(ans)