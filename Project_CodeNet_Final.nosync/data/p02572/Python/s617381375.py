(N, ) = [int(n) for n in input().split()]
A = [int(n) for n in input().split()]

NUM = 1000000007
inv2 = 500000004
assert (inv2 * 2) % NUM == 1

As2 = 0
A2s = 0

for a in A:
    As2 += a
    As2 %= NUM
    
    A2s += a ** 2
    A2s %= NUM

As2 = (As2 ** 2) % NUM

ans = (As2 + NUM - A2s) % NUM
ans *= inv2
ans %= NUM

print(ans)


