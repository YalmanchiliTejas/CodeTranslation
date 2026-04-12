N = int(input())
A = list(map(int, input().split()))

B = [[0] * 2 for i in range(300000)]
for i in range(N):
    if i == 0:
        B[0][0] = 0
        B[0][1] = A[0]
    elif i == 1:
        B[1][0] = 0
        B[1][1] = max([A[0], A[1]])
    elif i % 2 == 0:
        B[i][0] = max([B[i-2][0] + A[i], B[i-1][1]])
        B[i][1] = B[i-2][1] + A[i]
    else:
        B[i][0] = max([B[i-2][0] + A[i], B[i-1][0]])
        B[i][1] = max([B[i-2][1] + A[i], B[i-1][1]])

if i % 2 == 0:
    print(B[N-1][0])
else:
    print(B[N-1][1])
