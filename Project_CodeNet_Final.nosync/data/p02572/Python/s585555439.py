p = (10 ** 9 + 7) * 2
N = int(input())
A = [int(x) for x in input().split()]
A2 = [(x ** 2) % p for x in A]
result = (((sum(A) % p) ** 2 - sum(A2) % p) % p) / 2
print(int(result))