num = int(input())
ar = list(map(int,input().split()))
mod = 10**9 + 7
somee = sum(ar)
ans = 0
for i in range(num):
    ans+=(somee-ar[i])*ar[i]
print((ans//2)%mod)