N = int(input())
A = list(map(int, input().split()))

A_sum = sum(A)
A_squaresum = sum([a ** 2 for a in A])
answer = ((A_sum ** 2 - A_squaresum) // 2) % (10 ** 9 + 7)

print(answer)