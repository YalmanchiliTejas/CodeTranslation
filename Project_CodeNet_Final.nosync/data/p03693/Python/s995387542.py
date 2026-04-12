x, y, z = map(int, input().split())
print("YES" if (x * 100 + y * 10 + z) % 4 == 0 else "NO")
