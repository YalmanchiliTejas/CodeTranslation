n=int(input())
list=input().split()
sum=0
for i in range(n):
 sum+=int(list[i])
sum=sum*sum
sum2=0
for i in range(n):
 sum2+=int(list[i])*int(list[i])
sum-=sum2
sum//=2
sum%=1000000007
print(int(sum))