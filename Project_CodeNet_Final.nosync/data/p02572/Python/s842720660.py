mod = 1000000007
n = int(input())
a = list(map(int, input().split()))
ans = 0
a_sum = sum(a) 
a_total = a_sum*a_sum
lat = 0
for i in a:
    lat = lat + i*i
ans = (a_total - lat) // 2
ans = ans%mod
print(ans)