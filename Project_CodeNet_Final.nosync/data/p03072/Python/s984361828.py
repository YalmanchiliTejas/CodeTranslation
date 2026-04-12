from collections import deque

n = int(input())
H = deque(map(int, input().split()))

ans = 0

h = 0

for i in range(n):
    h2 = H.popleft()
    if h2 >= h:
        ans += 1
    h = max(h, h2)

print(ans)