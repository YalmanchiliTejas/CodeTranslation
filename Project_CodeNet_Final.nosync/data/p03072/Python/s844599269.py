from sys import stdin
input = lambda: stdin.readline().rstrip()
n = int(input())
h = list(map(int, input().split()))
max_h = h[0]
ans = 1
for i in range(1, n):
    if h[i] >= max_h:
        ans += 1
        max_h = h[i]
print(ans)
