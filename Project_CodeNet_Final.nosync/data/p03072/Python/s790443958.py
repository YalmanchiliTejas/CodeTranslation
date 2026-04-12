n = int(input())
h = list(map(int, input().split()))
prev = 0
ans = 0
for i in h:
    if i >= prev:
        ans += 1
    prev = max(prev, i)
print(ans)