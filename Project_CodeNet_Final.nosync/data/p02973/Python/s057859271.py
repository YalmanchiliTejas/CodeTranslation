import bisect
N = int(input())
A = [int(input())for i in range(N)]
m = [-A[0]]
ans = 1
for i in A[1:]:
    p = bisect.bisect_left(m,-i+1)
    if p == ans:
        ans += 1
        m.append(-i)
    else:
        m[p] = -i
print(ans)
