import sys
input = sys.stdin.readline

def multipleSum(A, n):
    sum = 0
    for i in range(n):
        sum += A[i]
    mulsum = sum*sum
    insum = 0
    for i in range(n):
        insum+=A[i]*A[i]
    return (mulsum-insum)//2

N = int(input())
A = list(map(int,input().split()))
n = len(A)
print(multipleSum(A,n)%1000000007)



