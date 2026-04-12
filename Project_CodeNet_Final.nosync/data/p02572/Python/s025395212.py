N = int(input())
l = list(map(int,input().split()))
mod = 10**9 + 7

area = sum(l) * sum(l)

for i in l:
    area -= i*i

ans = area//2
ans = ans % mod
print(ans)