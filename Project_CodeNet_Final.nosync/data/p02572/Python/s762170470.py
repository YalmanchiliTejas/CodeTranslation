N = int(input())
A = list(map(int, input().split()))
B = sum(map(lambda x: x ** 2, A))

print(((sum(A) ** 2 - B) // 2) % (10 ** 9 + 7))