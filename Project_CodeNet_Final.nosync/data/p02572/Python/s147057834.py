n = int(input())
a = list(map(int,input().split()))
mod = (10 ** 9) + 7
suma = sum(a)
tmp = 0
for i in a:
         tmp += (suma - i) * i
print((tmp // 2) % mod)
