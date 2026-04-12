n = int(input())
a = list(map(int,input().strip().split()))[:n]
sum=0 
sqsum=0
MOD=1000000007
for x in a:
    sum = sum+x
    sqsum = sqsum+ x*x

sum = sum*sum

ans = (sum-sqsum)//2
ans = ans%MOD
print(ans)