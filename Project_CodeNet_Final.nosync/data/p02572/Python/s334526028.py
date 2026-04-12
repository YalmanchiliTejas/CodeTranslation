MOD = 10 ** 9 + 7

n=int(input()) #3
alst=list(map(int,input().split())) #[1,2,3]

s=[0]
for i in range(len(alst)):
  s.append(s[i]+alst[i])

sum=0

for i in range(len(alst)-1):
  sum+=alst[i]*(s[len(s)-1]-s[i+1])

print(sum%MOD)