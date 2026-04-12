from bisect import bisect_right as br
n = int(input())
a = [int(input()) for _ in range(n)][::-1]
INF = float("INF")
lst = [INF]*n
ans = 0
for i in range(n):
    l = br(lst,a[i])
    lst[l] = a[i]
    ans = max(l+1,ans)
print(ans)