from bisect import bisect_right
n = int(input())
ans = 1
data = [-int(input())]
for i in range(n-1):
    x = -int(input())
    j = bisect_right(data,x)
    if j == ans:
        data.append(x)
        ans += 1
    else:
        data[j] = x
print(ans)