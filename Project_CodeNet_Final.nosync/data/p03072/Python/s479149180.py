N = int(input())
H = list(map(int, input().split()))
count = 1

for i in range(1, N):
    f = True
    for j in range(0, i):
        if H[j] > H[i]:
            f = False
            break
    if f:
        count += 1
print(count)