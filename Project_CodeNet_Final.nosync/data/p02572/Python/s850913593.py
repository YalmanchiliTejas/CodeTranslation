MOD = 10 ** 9 + 7

n=int(input())
alst=list(map(int,input().split()))

total=sum(alst)
sum=0

# for i in range(n-1):
#   for j in range(i+1,n):
#     sum=pow(sum+alst[i]*alst[j],1,MOD)

# print(sum)

for a in alst:
  sum = sum+a * (total - a)
  sum %= MOD

sum *= pow(2, MOD - 2, MOD)
sum %= MOD
print(sum)