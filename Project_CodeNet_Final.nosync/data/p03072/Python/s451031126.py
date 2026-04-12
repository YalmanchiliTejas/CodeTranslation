n = int(input())
h = list(map(int, input().split()))
ans = 0
tmpmax = 0
for i, item in enumerate(h):
    if i == 0:
        ans += 1
        tmpmax = item
    elif tmpmax <= item:
        ans += 1
        tmpmax = item
print(ans)
