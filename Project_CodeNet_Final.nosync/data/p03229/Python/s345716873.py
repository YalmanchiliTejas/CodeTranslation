N = int(input())
A = [int(input()) for i in range(N)]

A.sort()
sum = 0
sum2 = 0

if N % 2 == 0:
    A1 = A[:(N//2)]
    A2 = A[(N//2):]
    for i in range(N//2):
        sum += A2[i] - A1[i]
        if i+1 != N//2:
            sum += A2 [i+1] - A1[i]

else:
    A1 = A[:(N//2)]
    A2 = A[(N//2)+1:]
    A3 = A[(N//2)]

    for i in range(N//2):
        sum += A2[i] - A1[i]
        if i+1 != N//2:
            sum += A2 [i+1] - A1[i]
    sum += A3 - A1[N//2 -1]

    sum2 += A2[0] - A3
    for i in range(N // 2):
        sum2 += A2[i] - A1[i]
        if i + 1 != N // 2:
            sum2 += A2[i + 1] - A1[i]

    if sum2 > sum:  sum = sum2

print(sum)