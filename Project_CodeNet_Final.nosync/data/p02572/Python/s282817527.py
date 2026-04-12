n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
x = [sum(a)]
for i in a:
    x.append((x[-1]-i)%mod)
r = 0
for i in range(len(a)-1):
    r = (r+a[i]*x[i+1])%mod
print(r)