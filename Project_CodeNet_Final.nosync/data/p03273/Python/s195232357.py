H, W = map(int, input().split())
a = [input() for i in range(H)]

a = ["".join(row) for row in zip(*a) if row.count("#") > 0]
a = ["".join(row) for row in zip(*a) if row.count("#") > 0]

print("\n".join(a))
