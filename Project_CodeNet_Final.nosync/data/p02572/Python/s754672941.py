import sys

input = sys.stdin.readline

MOD = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))

ans2 = (sum(a) % MOD) ** 2 - sum(ai ** 2 for ai in a)

if ans2 % 2 != 0:
    ans2 += MOD
ans = (ans2 // 2) % MOD
print(ans)
