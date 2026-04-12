n = int(input())
h = list(map(int, input().split()))
max = 0
cnt = 0
for i in range(n):
    if h[i] >= max:
        cnt += 1
        max = h[i]
    else:
        continue
print(cnt)