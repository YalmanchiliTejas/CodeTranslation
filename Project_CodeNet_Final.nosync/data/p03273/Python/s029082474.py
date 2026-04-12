H, W = [int(_) for _ in input().split()]

A = [input() for i in range(H)]

A = ["".join(row) for row in zip(*A) if row.count("#") > 0]
A = ["".join(row) for row in zip(*A) if row.count("#") > 0]

print("\n".join(A))
