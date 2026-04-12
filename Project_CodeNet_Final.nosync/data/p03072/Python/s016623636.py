#ABC 124, B - great ocean view
n = int(input())
H = [int(el) for el in input().split(' ')]

count = 1
max_h = H[0]
for i in range(1, n):
    if H[i] - max_h >= 0:
        count += 1
        max_h = H[i]

print(count)
