from bisect import bisect_right

N = int(input())
A = [int(input()) for _ in range(N)]
B = [A[-1]]
ans = 1
for a in reversed(A[:-1]):
    idx = bisect_right(B, a)
    if idx == ans:
        B.append(a)
        ans += 1
    else:
        B[idx] = a
print(ans)