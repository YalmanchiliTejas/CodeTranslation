n, x, m = (int(x) for x in input().split())
A = [x]
used = {x, }
while True:
    x = pow(x, 2, m)
    if x in used:
        index = A.index(x)
        break
    else:
        A.append(x)
        used.add(x)
if n <= len(A):
    print(sum(A[:n]))
else:
    ans = sum(A)
    n -= len(A)
    m = len(A) - index
    ans += (n // m) * sum(A[index:])
    ans += sum(A[index:index + (n % m)])
    print(ans)