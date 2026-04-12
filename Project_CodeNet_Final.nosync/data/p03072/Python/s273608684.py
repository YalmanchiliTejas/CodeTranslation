N = int(input())
H = list(map(int, input().split()))

count = 0
for i in range(N-1, 0, -1):
    icount = 0
    for j in range(0, i):
        if H[i] >= H[j]:
            icount += 1
        else:
            break
    if icount == i:
        count += 1

print(count+1)