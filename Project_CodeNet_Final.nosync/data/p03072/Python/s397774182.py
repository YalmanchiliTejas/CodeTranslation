N = int(input())
H = list(map(int, input().split()))
maxH = 0
count = 0
for x in range(N):
    if H[x] >= maxH:
        count += 1
        maxH = H[x]
print(count)
