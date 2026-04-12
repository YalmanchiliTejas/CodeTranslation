r, g, d = map(int, input().split(' '))

print("YES" if (10 * g + d) % 4 == 0 else "NO")
