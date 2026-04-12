from sys import stdin
input = stdin.readline

def SumOfProductParis(n):
    if n == 0:
        return 0
    elif n == 1:
        return A[0]
    else:
        result = 0
        temp = sum(A)
        result = temp**2
        for i in range(n):
            result -= A[i]**2
        return (result//2)%(10**9+7)

N = int(input())
A = list(map(int, input().split()))

print(SumOfProductParis(N))