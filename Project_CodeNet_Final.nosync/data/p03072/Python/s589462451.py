n = int(input())
h = [int(i) for i in input().split()]

counter = 0
imax = 0

for i in range(n):
    if h[i] >= imax:
        counter += 1
        imax = h[i]


print(counter)