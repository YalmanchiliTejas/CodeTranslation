N = int(input())
H = list(map(int, input().split()))

count = 0
for i in range(N):
    flg = True
    for j in range(i):
        if H[i] < H[j]:
            flg = False
            break
    if flg:
        count += 1
print(count)