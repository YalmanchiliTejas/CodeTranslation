N = int(input())

A = list(map(lambda x: int(x), input().split(' ')))

res = ((sum(A)**2 - sum(list(map(lambda x: x**2, A)))) // 2) % (10**9 + 7)

print(int(res))
