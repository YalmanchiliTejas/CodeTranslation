import sys

MOD = 10**9 + 7

N = int(input())
As = list(map(int, input().split()))

sumA = 0
for A in As:
    sumA += A
    sumA %= MOD
#print('# sumA:', sumA, file=sys.stderr)

ans = sumA * sumA % MOD
for A in As:
    ans -= A * A % MOD
    ans %= MOD
#print('# ans:', ans, file=sys.stderr)

inv2 = pow(2, MOD-2, MOD)
ans *= inv2
ans %= MOD

print(ans)
