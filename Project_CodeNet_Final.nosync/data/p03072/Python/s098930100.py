n = int(input())
data = list(map(int, input().split()))

ans = 1
max_ = data[0]
for i in range(1, n):
    if max_ <= data[i]:
        max_ = data[i]
        ans += 1

print(ans)
