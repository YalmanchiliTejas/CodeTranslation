N,X,M = map(int,input().split())
A = X%M
Ans = A
Modset = set()
Modset.add(A)
i = 1
for _ in range(10**6):
    A = pow(A,2,M)
    if A not in Modset:
        Modset.add(A)
        Ans += A
        i += 1
    else:
        break
if 0 in Modset:
    print(Ans)
else:
    S = A
    B = A
    j = 1
    for _ in range(10**6):
        B = pow(B,2,M)
        if A != B:
            S += B
            j += 1
        else:
            break
    rep = (N-i)//j
    Ans += S*rep
    i += j*rep
    if i < N:
        i += 1
        Ans += A
        for _ in range(10**10):
            if i == N:
                break
            else:
                i += 1
                A = pow(A,2,M)
                Ans += A
    print(Ans)