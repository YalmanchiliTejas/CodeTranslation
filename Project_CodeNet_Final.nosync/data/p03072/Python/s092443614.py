N = int(input())
H = [int(i) for i in input().split()]

flag = True
count = 0
for i in range(len(H)):
    for j in range(i):
        if H[i] < H[j]:
            flag = False
            break
    if flag == True:
        count += 1
    else:
        flag = True

print(count)