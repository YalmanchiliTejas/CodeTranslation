N = int(input())
Hs = list(map(int, input().split()))

count = 0

hs_len = len(Hs)
for i, H in enumerate(Hs):
    flag = True
    for j in range(i, -1, -1):
        if Hs[j] > H:
            flag = False
            break

    if flag:
        count += 1

print(count)