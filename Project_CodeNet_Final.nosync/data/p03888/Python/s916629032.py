def solve(r1, r2):
    return float(r1*r2) / (r1+r2)
assert abs(solve(2, 3) - 1.2000000000) < 1e-6
assert abs(solve(100, 99) - 49.7487437186) < 1e-6
r1, r2 = map(int, raw_input().split())
print solve(r1, r2)