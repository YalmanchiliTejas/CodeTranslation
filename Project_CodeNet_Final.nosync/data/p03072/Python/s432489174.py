N = int(input())
H = list(map(int, input().split()))

flag = False
sum = 1

for i in range(1, N):
    for j in range(0, i):
        if H[j] > H[i]:
            flag = False
            break
        flag = True
    if flag == True:
        sum = sum + 1
        flag = False

print(sum)