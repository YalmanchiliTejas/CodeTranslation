N = int(input())
h = list(map(int, input().split()))

hmax = 0
ans = 0

for i in h:
    if hmax <= i:
        ans += 1
        hmax = i
print(ans)
