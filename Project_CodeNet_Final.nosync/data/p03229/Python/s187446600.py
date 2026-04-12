n = int(input())
A = [int(input()) for _ in range(n)]

A.sort()

if n%2 == 0:
    ans = A[n//2]-A[n//2-1]
    m = A[n//2]-A[n//2-1]
    for i in range(n):
        if i == n//2-1 or i == n//2:
            continue
        else:
            if i <= n//2:
                ans += m-2*A[i]
            else:
                ans += 2*A[i]-m
else:
    m = A[n//2]
    ans1 = m-A[n//2-1]
    for i in range(n):
        if i == n//2-1 or i == n//2:
            continue
        else:
            ans1 += 2*abs(A[i]-m)
    m = A[n//2]
    ans2 = A[n//2+1]-m
    for i in range(n):
        if i == n//2+1 or i == n//2:
            continue
        else:
            ans2 += 2*abs(A[i]-m)
    ans = max(ans1, ans2)
print(ans)
