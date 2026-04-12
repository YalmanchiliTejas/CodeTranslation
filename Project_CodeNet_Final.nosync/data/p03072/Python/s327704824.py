N = int(input())
H = [int(w) for w in input().split()]
assert len(H) == N

v = sum(1 for i in range(N) if max(H[:i], default=0) <= H[i])
print(v)