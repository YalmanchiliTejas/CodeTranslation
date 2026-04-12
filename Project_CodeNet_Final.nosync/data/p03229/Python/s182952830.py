n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
front = a[n - 1]
back = a[n - 1]
i = 0
j = n - 2
ans = 0
while i <= j:
    diff1 = abs(front - a[i])
    diff2 = abs(back - a[i])
    diff3 = abs(front - a[j])
    diff4 = abs(back - a[j])
    mx = max(diff1, diff2, diff3, diff4)
    ans += mx
    if mx == diff1:
        front = a[i]
        i += 1
    elif mx == diff2:
        back = a[i]
        i += 1
    elif mx == diff3:
        front = a[j]
        j -= 1
    else:
        back = a[j]
        j -= 1
print(ans)
