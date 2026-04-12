l=input().split()
n=int(l[0])
x=int(l[1])
m=int(l[2])
hashi=dict()
pref=0
count=0
prefix=[]
for i in range(n):
    if(i==0):
        ans=x%m
    else:
        ans=ans*ans
        ans%=m
    if(ans in hashi):
        period=i-(hashi[ans][0])
        num1=hashi[ans][0]
        k=(n-num1)//period
        rem=(n-(num1+k*period))
        count=count+prefix[num1]
        count=count+k*(pref-hashi[ans][1])
        for j in range(rem):
            if(j!=0):
                ans=ans*ans
            ans%=m
            count+=ans
        break
    hashi[ans]=(i,pref)
    prefix.append(pref)
    pref+=ans
print(max(pref,count))
