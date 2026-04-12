from bisect import bisect
n = int(input())
A = [int(input()) for i in range(n)]
ans = []
for a in A:
    i = bisect(ans,-a)
    if len(ans) == i:
        ans.append(-a)
    else:
        if -a<ans[i]: ans[i]=-a
print(len(ans))
