n = int(input())
h = list(map(int, input().split()))
highest = 0
cnt = 0
for i in range(n):
    if h[i] >= highest:
        cnt += 1
    highest = max(highest, h[i])
print(cnt)