n = int(input())
h = list(map(int, input().split()))
total = 1

for i in range(1, n):
    no_flag = 0
    for j in range(i):
        if h[j] > h[i]:
            no_flag = 1
        else:
            pass
    if no_flag == 0:
        total += 1

print(total)