n = int(input())
a = list(map(int,input().split()))


p = 10**9+7

ans = 0
s = sum(a)%p
ans = (s**2)%p
for i in range(n):
    ans -= (a[i]**2)%p
t = ans%p
if t%2==0:
    print(t//2)
else:
    print((t+p)//2)