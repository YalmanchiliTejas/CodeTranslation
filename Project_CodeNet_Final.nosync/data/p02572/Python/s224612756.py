n = int(input())
lis = list(map(int, input().split()))

mod = 10**9+7

s = sum(lis)
tmp = 0
for i in lis:
    tmp += i**2

print(((s*s - tmp)//2) % mod)