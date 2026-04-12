n = int(input())
h = list(map(int, input().split()))

max_h = 0
ans = 0
for i in range(len(h)):
    if h[i] >= max_h:
        ans += 1
        max_h = h[i]
print(ans)