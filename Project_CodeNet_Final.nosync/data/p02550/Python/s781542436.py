N, X, M = list(map(int, input().split()))

A = X
sum_A = A
A_list = [X]
for i in range(1, N):
    A = A ** 2 % M

    if (A in A_list):
        start = A_list.index(A)
        loop = A_list[start:]
        sum_A += sum(loop)*((N-i)//len(loop)) + sum(loop[:(N-i) % len(loop)])
        break
    else:
        A_list.append(A)
    sum_A += A

    if (A == 0):
        break

print(sum_A)
