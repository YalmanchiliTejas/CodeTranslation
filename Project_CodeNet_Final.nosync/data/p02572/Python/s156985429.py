N = int(input())
As = list(map(int, input().split()))

sA = sum(As) % (10 ** 9 + 7)
print((sA * sA - sum( (A * A % (10 ** 9 + 7) for A in As) ) ) * pow(2, -1, 10 ** 9 + 7) % (10 ** 9 + 7))
