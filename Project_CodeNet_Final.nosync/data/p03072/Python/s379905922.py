n = int(input())
h = list(map(int, input().split()))

ans = 1
for i in range(1, n):
    cnt = 0
    for j in range(0, i):
        if h[j] <= h[i]:
            cnt += 1
            if cnt == i:
                ans += 1

print(ans)
