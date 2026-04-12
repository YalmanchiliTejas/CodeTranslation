n=int(input())
s=input()
l=list(s.split())
sum1=0
sum2=0
for i in range(0,n):
    sum1=sum1+int(l[i])
    sum2=sum2+(int(l[i])*int(l[i]))
ans=((sum1**2)-sum2)//2
ans=ans%1000000007
print(ans)
