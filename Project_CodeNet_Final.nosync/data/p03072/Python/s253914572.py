N = int(input())
H = [int(x) for x in input().split()]

highest = 0
count = 0
for i in range(N):
    if H[i] >= highest:
        count += 1
        highest = H[i]

print(count)
