n = int(input())
A = sorted(int(input())for _ in range(n))

if n % 2 == 0:
    low = A[:n//2]
    high = A[n//2:]
    ans = abs(2*sum(high)-high[0]-(2*sum(low)-low[-1]))
else:
    low = A[:n//2]
    high = A[n//2+1:]
    mid = A[n//2]
    ans = abs(2*sum(high)-high[0]-(2*sum(low)-low[-1]))
    ans += max(high[0]-mid, mid-low[-1])
print(ans)