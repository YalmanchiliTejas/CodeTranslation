n = int(input())
H = list(map(int, input().split()))

ocean = 1
for i in range(1, n):
    count = 0
    for j in range(0, i):
        if H[j] > H[i]:
            count += 1
        if count >= 1:
            break
    if count == 0:
        ocean += 1

if n == 1:
    print(1)
else:
    print(ocean)