n = int(input())
h = list(map(int, input().split()))

max_ = 0
cnt = 0

for i in range(n):
    if h[i] >= max_:
        cnt += 1
        max_ = h[i]

print(cnt)