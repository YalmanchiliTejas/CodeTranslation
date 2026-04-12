import math

N=input().replace('\n','')
K=int(input().replace('\n',''))

def C(n,k):
    return (math.factorial(n)//math.factorial(n-k))//math.factorial(k)

def calc(n,k):
    if n<k or k<0:
        return 0
    return (9**k)*C(n,k)

s=0
l=len(N)
counter=0
for i,num in enumerate(N):
    if (K-counter)==0:
        s+=1
        break
    if int(num)==0:
        continue
    if i==l-1:
        s+=(int(num))*calc(l-i-1,K-counter-1)
    else:
        s+=(int(num)-1)*calc(l-i-1,K-counter-1)
    s+=calc(l-i-1,K-counter)
    counter+=1

print(s)