n, h = int(input()), [0] + list(map(int, input().split()))
print(len([i for i, x in enumerate(h[2:], start=2) if max(h[:i]) <= h[i]]) + 1)
