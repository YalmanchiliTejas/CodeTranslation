N = int(input())
h = list(map(int, input().split()))

counter = 1
for i in range(1, N):
    flag = 1
    for j in range(i):
        if h[i] - h[j] < 0:
            flag = 0
    if flag == 1:
        counter += 1

print(counter)
