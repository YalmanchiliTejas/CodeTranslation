from sys import stdin

N = int(stdin.readline().rstrip())
data = [int(x) for x in stdin.readline().rstrip().split()]

ans = 0
f = False
for i in range(N):
    for j in range(i):
        if data[j] > data[i]:
            f = True
    if not f:
        ans += 1
    f = False

print(ans)