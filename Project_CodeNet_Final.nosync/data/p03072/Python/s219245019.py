n = int(input())
h = list(map(int,input().split()))

cnt = 0
key = h[0]
for i in range(n):
    if key <= h[i]:
        cnt += 1
        key = h[i]

print(cnt)
