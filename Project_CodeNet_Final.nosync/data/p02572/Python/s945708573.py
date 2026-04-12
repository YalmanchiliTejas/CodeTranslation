input()
a = *map(int, input().split()),
print(((sum(a)**2 - sum(x * x for x in a)) // 2) % (10**9 + 7))
