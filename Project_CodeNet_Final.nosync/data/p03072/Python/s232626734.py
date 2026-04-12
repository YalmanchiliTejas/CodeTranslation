n = int(input())
h = list(map(int, input().split()))
m = 0
cnt = 0
for i in range(n):
    if h[i] >= m:
        cnt += 1
        m = h[i]
print(cnt)