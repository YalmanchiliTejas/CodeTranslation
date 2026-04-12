N = int(input())
A = [int(input()) for _ in range(N)]
A = sorted(A)

ans1 = 0
l = 0
r = N-1
for i in range(N-2):
    if i%2 == 0:
        ans1 += 2 * A[r]
        r -= 1
    else:
        ans1 += -2 * A[l]
        l += 1
if N%2 == 0:
    ans1 -= min(A[l], A[r])
    ans1 += max(A[l], A[r])
else:
    ans1 -= (A[l] + A[r])

ans2 = 0
l = 0
r = N-1
for i in range(N-2):
    if i%2 == 1:
        ans2 += 2 * A[r]
        r -= 1
    else:
        ans2 += -2 * A[l]
        l += 1
if N%2 == 0:
    ans2 -= min(A[l], A[r])
    ans2 += max(A[l], A[r])
else:
    ans2 += (A[l] + A[r])

print(max(ans1,ans2))
