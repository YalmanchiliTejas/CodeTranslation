import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int,input().split()))

ans = -float("inf")
if n % 2 == 0:
    D = [[0,0] for i in range(n//2)]
    D[0][0] = A[0]
    D[0][1] = A[1]
    for i in range(1, n//2):
        D[i][0] = D[i-1][0] + A[i*2]
        D[i][1] = max(D[i-1][0],D[i-1][1]) + A[i*2+1]
    print(max(D[-1]))

else:

    

    D = [[0,0] for i in range(n//2)]
    D[0][0] = A[0]
    D[0][1] = A[1]
    for i in range(1, n//2):
        D[i][0] = D[i-1][0] + A[i*2]
        D[i][1] = max(D[i-1][0],D[i-1][1]) + A[i*2+1]


    S = [0] * n
    S[0] = A[0]
    S[1] = A[1]
    for i in range(2, n):
        S[i] = A[i] + S[i-2]

    # print(S)
    

    for i in range(0, n, 2):
        le = max(D[i//2-1]) if i>0 else 0
        ri = S[-1] - S[i]
        # print(i,le,ri, le+ri)
        ans = max(ans, le+ri)

    A = A[::-1]

    D = [[0,0] for i in range(n//2)]
    D[0][0] = A[0]
    D[0][1] = A[1]
    for i in range(1, n//2):
        D[i][0] = D[i-1][0] + A[i*2]
        D[i][1] = max(D[i-1][0],D[i-1][1]) + A[i*2+1]
    # print(D[-1])

    S = [0] * n
    S[0] = A[0]
    S[1] = A[1]
    for i in range(2, n):
        S[i] = A[i] + S[i-2]
    

    for i in range(0, n, 2):
        le = max(D[i//2-1]) if i>0 else 0
        ri = S[-1] - S[i]
        # print(i,le,ri, le+ri)
        ans = max(ans, le+ri)

    print(ans)