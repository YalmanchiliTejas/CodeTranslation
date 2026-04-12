N = int(input())
A = list(map(int, input().split()))
A2 = list(map(lambda x: x ** 2, A))

sumA = sum(A)
sumA2 = sum(A2)

ans = (((sumA ** 2) - sumA2) // 2) % 1000000007

print(ans)
