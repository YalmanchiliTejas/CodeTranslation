n, x, m = map(int, input().split())
A = [0, x]
d = {x:1}
for i in range(2, n+1):
    A.append(A[i-1]**2 % m)
    if A[i] in d:
        j = d[A[i]]
        q, r = divmod(n-j+1, i-j)
        print(sum(A[:j]) + q*sum(A[j:i]) + sum(A[j:j+r]))
        break
    else:
        d[A[i]] = i
else:
    print(sum(A))