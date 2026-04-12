n = int(input())
h = list(map(int, input().split()))

high, cnt = 0, 0

for i in range(n):
    if high <= h[i]:
        cnt += 1
        high = h[i]
print(cnt)