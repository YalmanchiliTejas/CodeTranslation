# B
n = int(input())
h = [int(i) for i in input().split()]

h_max = 0
count = 0

for i in range(n):
    if h_max <= h[i]:
        h_max = h[i]
        count += 1
print(count)

