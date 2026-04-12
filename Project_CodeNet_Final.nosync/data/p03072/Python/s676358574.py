N = int(input())
H = list(map(int, input().split()))
max_v = H[0]
count = 1
for i in range(1, N):
    if max_v <= H[i]:
        count += 1
        max_v = H[i]
print(count)