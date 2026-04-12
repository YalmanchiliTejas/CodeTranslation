N = int(input())
H = list(map(int, input().split()))
max_height = 0
counter = 0
for i in range(N):
    if max_height <= H[i]:
        counter += 1
    max_height = max(max_height, H[i])
print(counter)