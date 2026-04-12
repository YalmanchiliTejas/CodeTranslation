N = int(input())
A = sorted([int(input()) for _ in range(N)])

if N % 2 == 1:
    A11 = A[:N//2+1]
    A12 = A[N//2+1:]
    ans1 = sum(A12)*2-sum(A11)*2+A11[-1]+A11[-2]

    A21 = A[:N//2]
    A22 = A[N//2:]
    ans2 = sum(A22)*2-sum(A21)*2-A22[0]-A22[1]

    ans = max(ans1, ans2)
else:
    A1 = A[:N//2]
    A2 = A[N//2:]
    ans = sum(A2)*2-sum(A1)*2+A1[-1]-A2[0]


print(ans)
