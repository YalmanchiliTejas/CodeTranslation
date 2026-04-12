n = int(input())
h = list(map(int, input().split()))
high = h[0]
cnt = 0
for i in range(n):
    if h[i] >= high:
        cnt += 1
        high = h[i]
print(cnt)