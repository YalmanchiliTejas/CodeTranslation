N = int(input())
A = list(map(int, input().split()))

if N % 2 == 0: #偶数のとき
    B = [0] * (N // 2 + 1)
    W = [0] * (N // 2 + 1)
    for i in range(N // 2):
        B[i + 1] = B[i] + A[2 * i]
    for i in range(N // 2 - 1, -1, -1):
        W[i] = W[i + 1] + A[2 * i + 1]

    # print (B)
    # print (W)

    ans = -10 ** 16
    for i in range(N // 2 + 1):
        ans = max(ans, B[i] + W[i])

    print (ans)
    exit()

DP0 = [[-10 ** 16] * 2 for _ in range(N + 1)]
DP1 = [[-10 ** 16] * 2 for _ in range(N + 1)]
DP2 = [[-10 ** 16] * 2 for _ in range(N + 1)]

DP0[N][0] = 0 #右端の外側を0に設定してスタート

for i in range(N - 1, -1, -1):
    a = A[i]
    
    DP0[i][0] = DP0[i + 1][1]
    DP0[i][1] = DP0[i + 1][0] + a

    DP1[i][0] = max(DP1[i + 1][1], DP0[i + 1][0])
    DP1[i][1] = DP1[i + 1][0] + a

    DP2[i][0] = max(DP2[i + 1][1], DP1[i + 1][0])
    DP2[i][1] = DP2[i + 1][0] + a
    
if N % 2 == 1:
    print (max(DP1[0][0], DP2[0][1]))
else:
    print (max(DP0[0][0], DP1[0][1]))

# for i in DP0:
#     print (i)

# for i in DP1:
#     print (i)

# for j in DP2:
#     print (j)