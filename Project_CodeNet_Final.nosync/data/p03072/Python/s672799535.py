n = int(input())
h = list(map(int, input().split()))

imax = 0
counter = 0
for i in range(n):
    if h[i] >= h[imax]:
        counter += 1
        imax = i
print(counter)