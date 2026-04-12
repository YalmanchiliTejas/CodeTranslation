n = int(input())
h = list(map(int, input().split()))

count = 1

for i in range(1, n): #判定する旅館
    tmp = 0
    for j in range(i): #高さを判定
        if h[j] <= h[i]:
            tmp += 1
    if tmp == i:
        count += 1

print(count)