


#for _ in range(int(input())):
n=int(input())
a=[int(x) for x in input().split()]  


p=[]
r=0
for x in a[::-1]:
   r+=x
   p.append(r)  
  
p=p[::-1]
ans=0
for i in range(0,n-1):

    ans+=(a[i]*p[i+1])
print(ans%1000000007)



