import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0

n = int(readline())
lst1 = list(map(int,readline().split()))
mod = 10**9+7

res = 0

ans = 0
al = sum(lst1)
for i in lst1:
    res += i
    ans += (al-res)*i
    ans %= mod

    

print(ans)