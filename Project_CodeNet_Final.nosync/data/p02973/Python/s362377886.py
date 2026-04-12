import bisect
n = int(input())
l = [0 for i in range(n)]
for i in range(n):
    a1 = int(input())
    l[n-1-i] = a1
h = [l[0]]
ans = 1
for i in range(1,n):
    a = bisect.bisect_right(h,l[i])
    if ans == a:
        ans += 1
        h.append(l[i])
    else:
        h[a] = l[i]
print(ans)