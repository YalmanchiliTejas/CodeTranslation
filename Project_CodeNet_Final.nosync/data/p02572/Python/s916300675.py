from sys import stdin
input = stdin.readline

def cumsum(xs):
    result = [xs[0]]
    for x in xs[1:]:
        result.append(result[-1] + x)
    return result

n = int(input().rstrip())
a = list(map(int, input().rstrip().split()))

ans = 0
MOD = 1000000007
s = cumsum(list(reversed(a)))

for i in range(n-1):
    ans += a[i] * s[n-2-i]

print(ans % MOD)
