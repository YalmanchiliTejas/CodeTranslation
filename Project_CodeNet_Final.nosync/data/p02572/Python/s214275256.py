N = int(input())
A = list(map(int, input().split()))

mod = 10 ** 9 + 7
sum = sum(A) **  2

squ = 0
for i in range(N):
    squ +=  A[i] ** 2

answer = int(((sum - squ)  //  2 ) % mod)
print(answer)