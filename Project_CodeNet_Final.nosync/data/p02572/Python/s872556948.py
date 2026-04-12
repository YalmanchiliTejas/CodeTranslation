# import sys
# input = sys.stdin.readline

def mp(): return map(int, input().split())
def lmp(): return list(map(int, input().split()))

n = int(input())
a = lmp()
mod = int(1e9+7)
ans = 0
num = sum(a)
for i in range(n-1):
    u = num - a[i]
    ans += a[i] * u
    ans %= mod
    num = u
print(ans)

