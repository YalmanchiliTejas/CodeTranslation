N = int(input())
h = list(map(int, input().split()))

max_h = h[0]
cnt = 1
for i in range(1,N):
    if h[i] >= max_h:
        max_h = h[i]
        cnt += 1
print(cnt)
