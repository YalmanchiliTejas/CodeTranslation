N = int(input())
H = list(map(int, input().split()))

count = 0
temp = 0
for i in range(N):
    if temp <= H[i]:
        count += 1
        temp = max(temp, H[i])

print(count)
