n = int(input())
h = list(map(int, input().split()))

cnt = 0

for i, v in enumerate(h):
    if v >= max(h[0:i+1]):
        cnt += 1


print(cnt)
