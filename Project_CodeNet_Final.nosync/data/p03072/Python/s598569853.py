n = int(input())
h = list(map(int, input().split()))

counter = 0
for i in range(n):
    flag = True
    for j in range(i):
        if h[j] > h[i]:
            flag = False
    if flag:
        counter += 1
print(counter)
