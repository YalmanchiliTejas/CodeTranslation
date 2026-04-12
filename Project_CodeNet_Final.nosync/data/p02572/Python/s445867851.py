n = int(input())
a = list(map(int, input().split()))

print(((sum(a)**2 - sum([e**2 for e in a])) // 2) % (10**9 + 7))
