import bisect

N = int(input())
A = [int(input()) for i in range(N)]

ans = 1
X = [-A[0]]
for i in range(1,N):
    if -X[ans-1] >= A[i]:
        X.append(-A[i])
        ans += 1
    else:
        pos = bisect.bisect_right(X,-A[i])
        X[pos] = -A[i]

print(ans)
