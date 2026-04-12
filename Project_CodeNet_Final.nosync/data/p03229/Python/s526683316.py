N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
ans = 0
left, right = 1, 0
el, er = A[0], A[0] 
while left + right < N:
    a = abs(A[left]-el)
    b = abs(A[left]-er)
    c = abs(A[-right-1]-el)
    d = abs(A[-right-1]-er)
    m = max(a, b, c, d)
    if m == a:
        ans += a
        el = A[left]
        left += 1
    elif m == b:
        ans += b
        er = A[left]
        left += 1
    elif m == c:
        ans += c
        el = A[-right-1]
        right += 1
    else:
        ans += d
        er = A[-right-1]
        right += 1

print(ans)