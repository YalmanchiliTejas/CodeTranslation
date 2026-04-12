n = input()
h = list(map(int,input().split()))

count = 1
for i in range(1, len(h)):
    flag = True
    for j in range(i):
        if (h[j] > h[i]):
            flag = False

    if flag:
        count += 1

print(count)
