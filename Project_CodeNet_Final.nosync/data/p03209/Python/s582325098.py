n, x = list(map(int, input().split()))

a = [0, 1]
b = [0, 1]
for i in range(n):
    a.append(a[i + 1] * 2 + 1)
    b.append(b[i + 1] * 2 + 3)

if b[-1] == x:
    print(a[-1])
    exit()

ans = 0
left = 0
mid = int(b[-1] / 2)
right = b[-1] - 1
i = len(b) - 1
while i > 0:
    if mid + 1 == x:
        ans += a[i - 1] + 1
        break
    elif mid < x:
        ans += a[i - 1] + 1
        left = mid + 1
        mid = mid + int((right - mid) / 2)
        right = right - 1
    else:
        right = mid - 1
        mid = mid - int((mid - left) / 2)
        left = left + 1
    i = i - 1

print(ans)