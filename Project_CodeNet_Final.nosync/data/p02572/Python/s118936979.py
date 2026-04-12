MOD = 10 ** 9 + 7

# [1,2,3,4,5,6]の時、累積和は、
# [0,1,3,6,10,15,21]
cumsum=[0]
def my_cumsum(alst):
  for i in range(len(alst)):
    cumsum.append(cumsum[i]+alst[i])
  return cumsum

n=int(input()) #3
alst=list(map(int,input().split()))

# 原因はnp.cumsum関数にある事が判明
# s=np.cumsum(alst)

s=my_cumsum(alst)

sum=0

for i in range(len(alst)-1):
  sum+=alst[i]*(s[len(s)-1]-s[i+1])

print(sum%MOD)