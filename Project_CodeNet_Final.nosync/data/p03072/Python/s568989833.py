n = int(input())
h = map(int, input().split())
h = list(h)
max_h = h[0]
cnt = 0

for a in h:
    if a >= max_h:
        cnt += 1
        max_h = a
print(cnt)