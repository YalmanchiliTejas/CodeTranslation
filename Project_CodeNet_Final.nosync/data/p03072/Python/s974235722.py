n = int(input())
count = 0
h = [int(s) for s in input().split()]
l = 0
for i in range(n):
    if h[l] <= h[i]:
        count += 1
        l = i
print(count)