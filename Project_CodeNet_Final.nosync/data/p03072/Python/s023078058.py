n = int(input())
h = list(map(int, input().split()))

ans = 0
max_ = 0
for i in h:
    if i >= max_:
        ans += 1
        max_ = i
print(ans)
