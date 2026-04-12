r, g, b = map(int, input().split())
ans = r * 100 + g * 10 + b

print("YES" if ans % 4 == 0 else "NO")
