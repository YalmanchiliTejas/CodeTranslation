N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

B = list(map(lambda x: x ** 2, A))

SA = sum(A)
SB = sum(B)

print(((SA * SA - SB) // 2) % mod)