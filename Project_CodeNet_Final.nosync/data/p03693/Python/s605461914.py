r, g, b = map(int, input().split())

n = int(str(r) + str(g) + str(b))
print("YES" if n % 4 == 0 else "NO")
