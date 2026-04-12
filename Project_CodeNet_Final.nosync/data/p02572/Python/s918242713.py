N = int(input())
A = list(map(int, input().split()))

x = sum(A)
y = sum([A[i] ** 2 for i in range(N)])

print(((x ** 2 - y) // 2) % (10 ** 9 + 7))