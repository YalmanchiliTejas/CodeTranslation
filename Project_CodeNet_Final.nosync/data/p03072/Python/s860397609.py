n = int(input())

h = list(map(int, input().split()))

max_h = 0
ans = 0
for i in h:
    if i >= max_h:
        ans += 1
    max_h = max(max_h,i)

print(ans)