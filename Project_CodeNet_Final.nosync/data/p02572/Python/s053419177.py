n = int(input())

a = list(map(int, input().split()))

S = sum(a)

S2 = sum(map(lambda x: x * x, a ))

ans = (S * S - S2) // 2 % 1000000007
print(ans)

