from sys import stdin

N, X = [int(x) for x in stdin.readline().rstrip().split()]
burger = [(1, 1)]
level = 0

while level < N:
    burger.append((burger[-1][0] * 2 + 3, burger[-1][1] * 2 + 1))
    level += 1

ans = 0
while N > 0 and X > 0:
    if X < burger[N - 1][0] + 2:
        N -= 1
        X -= 1
    if X == burger[N - 1][0] + 2:
        ans += 1
        X -= 2
        N -= 1
    if burger[N - 1][0] + 2 < X:
        X -= burger[N - 1][0] + 2
        ans += burger[N - 1][1] + 1
        N -= 1
if N == 0 and X > 0:
    ans += 1

print(ans)
