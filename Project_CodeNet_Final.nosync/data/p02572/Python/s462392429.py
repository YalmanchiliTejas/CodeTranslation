n = int(input())
a = list(map(int, input().split()))
all = sum(a)
mod = pow(10, 9)+7
all %=mod
count = 0
for i in range(n-1):
    all=(all+mod-a[i])%mod
    x = a[i]
    seki = (x*all)%mod
    count += seki
    count%=mod
print(count)