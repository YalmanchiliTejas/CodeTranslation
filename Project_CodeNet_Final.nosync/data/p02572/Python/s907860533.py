N=int(input())
A=list(map(int,input().split()))

modular=10**9+7
sum=0

AllSum=0
for i in range(N):
  AllSum+=A[i]
  AllSum=AllSum%modular

  
RuisekiWa=[]
NextSum=AllSum

for i in range(N):
  RuisekiWa.append((NextSum-A[i])%modular)
  NextSum=RuisekiWa[i]

#print(RuisekiWa)
for i in range(N):
  sum+=(A[i]*RuisekiWa[i])%modular
  sum=(sum%modular)
    
print(sum%modular)
