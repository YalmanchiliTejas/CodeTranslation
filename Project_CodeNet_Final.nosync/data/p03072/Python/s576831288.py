n, *h = map(int, open(0).read().split())

high = h[0] 
cnt = 1
for i in range(1, n):
    if high <= h[i]:
        cnt += 1
        high = h[i]

print(cnt)