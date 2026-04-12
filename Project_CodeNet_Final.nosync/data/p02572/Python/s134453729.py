N = int(input())

A = list(map(int, input().split()))

mod = 10 ** 9 + 7

temp = 0

for i in range(N):

    temp += (A[i] ** 2) 

print(((((sum(A) ** 2) ) - (temp)) // 2) % mod)
