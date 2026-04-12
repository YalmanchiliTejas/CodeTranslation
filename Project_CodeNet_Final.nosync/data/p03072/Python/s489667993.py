n = int(input())
a = list(map(int, input().split()))

t = a[0]
ans = 0
for i in range(n):
    if t > a[i]:
        continue
    else:
        t = a[i]
        ans += 1

print(ans)
