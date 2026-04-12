N, X, M = map(int, input().split())
A = [0]*(M+1)
A[0] = X
ls, rs = 0, 0
m = [-1]*(M+1)
m[X] = 0
for i in range(1, M+1):
    A[i] = (A[i-1]*A[i-1]) % M
    if m[A[i]] >= 0:
        ls = m[A[i]]
        rs = i
        break
    m[A[i]] = i

if rs == 0:
    print(sum(A[:N]))
else:
    if ls > N:
        print(sum(A[:N]))
    else:
        ans = sum(A[:ls])
        N -= ls
        w = rs-ls
        ans += sum(A[ls:rs])*(N//w)
        ans += sum(A[ls:ls+N % w])
        print(ans)
