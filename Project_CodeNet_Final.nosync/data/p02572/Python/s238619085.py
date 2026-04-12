N = int(input())
A = [int(a) for a in input().split()]
print((sum(A) ** 2 - sum([a ** 2 for a in A])) // 2 % (10 ** 9 + 7))