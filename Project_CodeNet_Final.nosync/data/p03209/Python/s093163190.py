# 解説AC

n, x = map(int, input().split())

# 層数、パティ数をA, Pに格納する
A = [1]
P = [1]
for i in range(n):
    A.append(A[i]*2 + 3)
    P.append(P[i]*2 + 1)

def f(n, x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x <= 1 + A[n-1]:
        return f(n-1, x-1)
    else:
        return P[n-1] + 1 + f(n-1, x-2-A[n-1])
print(f(n, x))
    