N = int(input())
H = list(map(int, input().split()))

count = 1
max_height = H[0]
for i in range(1, N):
    if max_height <= H[i]:
        count += 1
    max_height = max(max_height, H[i])
print(count)