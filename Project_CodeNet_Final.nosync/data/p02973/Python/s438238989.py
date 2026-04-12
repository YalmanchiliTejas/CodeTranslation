import bisect
n = int(input())
a = [int(input()) for i in range(n)]
ans = 0
color = [a[n-1]]
for i in range(n-2,-1,-1):
    x = bisect.bisect_right(color,a[i])
    if x == len(color):
        color.append(a[i])
    else:
        color[x] = a[i]
print(len(color))