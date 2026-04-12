A, B, C, X, Y = map(int, input().split())
pa = A * X
pb = B * Y
pab = pa + pb
pc_max = C * max(X, Y) * 2
pc_min = C * min(X, Y) * 2
if X > Y:
    n = X - Y
    pc_min += A * n
else:
    n = Y - X
    pc_min += B * n
print(min(pab, pc_max, pc_min))