n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()

if n == 2:
    print(a[1] - a[0])
    exit()

ans = 0
middles = [n // 2 - 1, n // 2, n // 2 + 1]
if middles.count(0):
    middles.remove(0)
if middles.count(n-1):
    middles.remove(n-1)
for mid in middles:
    l = 0; r = n-1
    val = abs(a[mid] - a[l])
    state = True 
    while l != r:
        val += abs(a[r] - a[l])
        if state:
            l += 1
            if l == mid:
                l += 1
            state = False
        else:
            r -= 1
            if r == mid:
                r -= 1
            state = True
    ans = max(ans, val)
for mid in middles:
    l = 0; r = n-1
    val = abs(a[mid] - a[r])
    state = True 
    while l != r:
        val += abs(a[r] - a[l])
        if state:
            r -= 1
            if r == mid:
                r -= 1
            state = False
        else:
            l += 1
            if l == mid:
                l += 1
            state = True
    ans = max(ans, val)
print(ans)