N = int(input())
H = list(map(int, input().split()))
count = 1
max = H[0]

for i in range(1, N):
    if H[i-1] <= H[i] and max <= H[i]:
        count += 1
    if max < H[i]:
        max = H[i]
        
print(count)