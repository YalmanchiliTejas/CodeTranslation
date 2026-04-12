N = int(input())
H = list(map(int, input().split()))
flag = 0
count = 1
for i in range(N):
    for j in range(0, i):
        if H[i] >= H[j]:
            flag = 1
        else:
            flag = 0
            break
    if flag == 1:
        count += 1
print(count)