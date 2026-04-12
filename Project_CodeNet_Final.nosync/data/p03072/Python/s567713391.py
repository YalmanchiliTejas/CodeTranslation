n = int(input())
h = list(map(int, input().split()))
ans = 1

for i in range(n):
    for j in range(i):
        if h[i] < h[j]:
            break
        if j == i - 1:
            ans += 1

print(ans)