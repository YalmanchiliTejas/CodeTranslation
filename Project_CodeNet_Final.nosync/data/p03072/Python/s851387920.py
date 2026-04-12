N = int(input())
H = [int(i) for i in input().split()]

count = 1
before = H[0]
for i in range(1, N):
    if before <= H[i]:
        count += 1
    before = max(before, H[i])

print(count)