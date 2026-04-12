n = int(input())
hn = list(map(int, input().split()))

count = 1
for i in range(1, n):
    flag = True
    for j in range(0, i):
        if hn[i] < hn[j]:
            flag = False
    if flag:
        count += 1
print(count)