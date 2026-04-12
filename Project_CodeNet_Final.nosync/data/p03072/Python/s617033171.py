N = int(input())
H = list(map(int, input().split()))

max_height = H[0]
count = 1
for i in range(1, N):
    if max_height <= H[i]:
        max_height = H[i]
        count += 1

print(count)         