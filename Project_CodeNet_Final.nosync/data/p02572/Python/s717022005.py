import numpy as np
MOD = 10 ** 9 + 7

n=int(input()) #3
alst=list(map(int,input().split())) #[1,2,3]

# 累積和を求める

# 例
# [1,2,3,4,5,6]の時、累積和は、
# [0,0+1,0+1+2,0+1+2+3,0+1+2+3+4,0+1+2+3+4+5,0+1+2+3+4+5+6]

s=[0]
for i in range(len(alst)):
  s.append(s[i]+alst[i])

sum=0

for i in range(len(alst)-1):
  sum+=alst[i]*(s[len(s)-1]-s[i+1])

print(sum%MOD)