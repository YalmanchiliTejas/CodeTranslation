n = int(input())
h = list(map(int, input().split()))
a = 1
for j in range(1, n):
    flag=False
    for i in range(0, j):
        if h[i] <= h[j]:
            flag = True
        else:
            flag = False
            break
    if flag:
        a = a + 1

print(a)