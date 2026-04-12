N = int(input())
H = list(map(int, input().split()))

count = 0
h = H[0]

for i in range(N):
    if h <= H[i]:
        count += 1
        h = H[i]

print(count)