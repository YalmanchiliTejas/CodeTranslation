from bisect import bisect

n = int(input())
ma = [-int(input()) for _ in range(n)]

ans = [ma[0]]
for ai in ma[1:]:
    tmp = bisect(ans, ai)
    if tmp == len(ans):
        ans.append(ai)
    elif tmp < len(ans):
        ans[tmp] = ai
print(len(ans))
