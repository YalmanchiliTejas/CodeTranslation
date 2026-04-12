# ABC 064: A – RGB Cards
r, g, b = [int(s) for s in input().split()]
print('YES' if (g * 10 + b) % 4 == 0 else 'NO')