n = int(input())
h = list(map(int, input().split()))
ans, count = 1, 0
for i in range(len(h)-1, 0, -1):
    for j in range(i-1, -1, -1):
        if h[i] >= h[j]:
            count += 1
    if count == i:
        ans += 1
    count = 0
print(ans)