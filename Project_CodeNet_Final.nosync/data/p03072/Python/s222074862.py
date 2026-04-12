N = int(input())
H = list(map(int, input().split()))
count = 1
high = H[0]
for i in range(1, N):
    if high <= H[i]:
        count += 1
        high = H[i]
print(count)
