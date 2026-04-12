n = int(input())
h = list(map(int, input().split()))

cnt = 0
flag = True
for i in range(1, n):
    for j in range(i):
        if h[i] < h[j]:
            flag = False
            break
    if flag:
        cnt += 1
    flag = True

print(cnt + 1)
