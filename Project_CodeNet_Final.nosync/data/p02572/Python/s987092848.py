S = int(input())
A = [int(x) for x in input().split()]

Sum = 0
Asum = sum(A) % 1000000007
for i in range(len(A) -1 ):
    b = A[i]
    Asum = Asum - b
    if Asum < 0:
        Asum = Asum + 1000000007
    Sum = (Sum + Asum * b) % 1000000007

print(Sum)
