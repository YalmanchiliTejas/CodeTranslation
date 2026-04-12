import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))
s = sum(a)
mod = 10**9+7

res = 0

for e in a:
    s -= e
    res = (res+s*e)%mod
print(res)