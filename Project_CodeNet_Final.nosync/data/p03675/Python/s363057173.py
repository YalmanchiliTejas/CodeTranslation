N = int(input())
A = list(input().split())

l = []
r = []
flag = False
if N % 2 == 0:
    for i in range(N-1, 0, -2):
        if flag:
            print(" ", end="")
        print(A[i], end="")
        flag = True
    for i in range(0, N, 2):
        if flag:
            print(" ", end="")
        print(A[i], end="")
else:
    for i in range(N-1, -1, -2):
        if flag:
            print(" ", end="")
        print(A[i], end="")
        flag = True
    for i in range(1, N, 2):
        if flag:
            print(" ", end="")
        print(A[i], end="")


print()
