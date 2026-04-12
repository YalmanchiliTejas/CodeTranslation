n = int(input())
x = list(map(int, input().split()))

edge = sum(x)
print((edge**2 - sum([X*X for X in x]))//2 % (10**9+7))