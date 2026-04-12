N = int(input())
A = list(map(int,input().split()))
def solver(N,A):
    powsum = sum([i ** 2 for i in A])
    return (sum(A) ** 2 - powsum) // 2 % 1000000007
print(solver(N,A))