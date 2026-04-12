N = int(input())
A = map(int,input().split())
ans = 0
ans2 = 0
mod = 10 ** 9 + 7
for a in A:
    ans += a
    ans2 += a**2

print(((ans **2 - ans2)//2)%mod)