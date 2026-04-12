n = int(input())
h = list(map(int, input().split()))
max = h[0]
cnt = 0
for i in range(n):
    if max <= h[i]:
        max = h[i]
        cnt += 1
print(cnt)