N = int(input())
H = [int(_) for _ in input().rstrip().split()]

maxH = H[0]
count = 1
for i in range(1,N):
    if H[i] >= maxH:
        count += 1
        maxH = H[i]

print(count)