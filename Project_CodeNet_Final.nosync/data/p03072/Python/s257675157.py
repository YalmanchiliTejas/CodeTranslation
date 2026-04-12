n = int(input())
h = [int(i) for i in input().split()]
m = 0
cnt = 0
for i in range(n):
    if h[i] >= m:
        m = h[i]
        cnt += 1
print(cnt)
