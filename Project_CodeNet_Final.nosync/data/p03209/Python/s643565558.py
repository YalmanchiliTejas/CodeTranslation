from itertools import accumulate
N, X = map(int, input().split())
P = list(accumulate([1]*(N+1), lambda acc,x: acc*2+1))
A = list(accumulate([1]*(N+1), lambda acc,x: acc*2+3))
ans = 0
for n in range(N-1, -1, -1):
    if X >= 2 * A[n] + 2:
        X -= 2 * A[n] + 2
        ans += 2 * P[n] + 1
    elif X >= A[n] + 2:
        X -= A[n] + 2
        ans += P[n] + 1
    elif X >= A[n] + 1:
        X -= A[n] + 1
        ans += P[n]
    elif X >= 1:
        X -= 1
    else:
        break
print(ans)