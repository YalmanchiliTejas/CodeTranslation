import sys

N = int(input())
A = list(map(int, input().split()))


def add(a, b, BIGMOD):
    return (a + b) % BIGMOD


def mul(a, b, BIGMOD):
    return (a * b) % BIGMOD


A_Sum = sum(A)
Sum = 0
BIGMOD = 10 ** 9 + 7

for i in range(N - 1):
    A_Sum -= A[i]
    Sum = add(Sum,mul(A[i], A_Sum, BIGMOD),BIGMOD)

print(Sum)