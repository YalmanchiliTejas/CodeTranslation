N = int(input())
H = list(map(int, input().split()))

count = 0
max_ = 0

for i in range(N):
    if H[i] >= max_:
        count += 1
        max_ = H[i]

print(count)