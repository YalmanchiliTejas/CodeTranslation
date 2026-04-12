n, k = map(int, input().split())

ret = 0

for b in range(k+1, n+1):
    div = n // b
    ama = n % b
    if k != 0:
        ret += div * (b - k) + max(ama - k + 1, 0)
    else:
        ret += div * (b - k) + max(ama, 0)

print(ret)
