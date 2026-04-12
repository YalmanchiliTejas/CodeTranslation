N = int(input())
h = list(map(int, input().split()))
count = 0
max_ = 0
for i in range(N):
    if max_ <= h[i]:
        count += 1
    max_ = max(max_, h[i])
print(count)
