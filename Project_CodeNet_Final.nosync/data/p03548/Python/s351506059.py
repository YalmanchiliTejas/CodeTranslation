X, Y, Z = map(int, input().split())

print((X-Y-2*Z)//(Y+Z) + 1 if X-Y-2*Z >= 0 else 0)