#!/usr/bin/env python3

MOD = 10**9
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    return divisors

A, B, C, X, Y = map(int, input().split())
AB = 2*C

xy_min = 0
xy_max = 0
if X > Y:
    xy_min = Y
    xy_max = X
else:
    xy_min = X
    xy_max = Y

ans2 = xy_max*AB


ans = 0
if A+B > AB:
    ans += AB*xy_min
    X -= xy_min
    Y -= xy_min

    ans += A*X
    ans += B*Y
else:
    ans += A*X
    ans += B*Y

print(min(ans, ans2))
