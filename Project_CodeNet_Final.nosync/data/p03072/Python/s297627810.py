n = int(input())
h = list(map(int, input().split()))

sum = 1

for i in range(1, n):
    flg = True
    for j in range(0, i):
        if h[i] < h[j]:
            flg = False
            break
    if flg:
        sum += 1

print(sum)