# ABC064A - RGB Cards
r, g, b = list(map(int, input().rstrip().split()))
print("YES" if (g * 10 + b) % 4 == 0 else "NO")