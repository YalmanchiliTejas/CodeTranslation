import sys

n, *aaa = map(int, sys.stdin.buffer.read().split())
ans = sum(aaa) ** 2
ans -= sum(a ** 2 for a in aaa)
ans //= 2
print(ans % (10 ** 9 + 7))
