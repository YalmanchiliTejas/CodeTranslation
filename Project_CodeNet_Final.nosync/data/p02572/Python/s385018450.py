n = int(input())
a = list(map(int,input().split()))

sum = 0
for i in a:
    sum += i

ans = 0
for i in range(n-1):
    sum -= a[i]
    ans += sum*a[i]
    
MOD = 1000000007
print( ans%MOD )