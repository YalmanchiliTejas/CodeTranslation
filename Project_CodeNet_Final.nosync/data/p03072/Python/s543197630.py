n = int(input())
h = list(map(int, input().split()))
cnt = 0
m = 0
for i in range(n):
    if i == 0:
        cnt += 1
        m = h[i]
    elif h[i-1] <= h[i] and h[i] >= m:
        m = h[i]
        cnt += 1
print(cnt)
