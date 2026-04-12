n=int(input())

a=list(map(int,input().split()))

s=[0]*(n) 
s[0]=a[n-1]
for i in range(1,n-1):
    s[i]=s[i-1]+a[n-1-i]
counter=0

for i in range(n-1):
    counter=counter+a[i]*s[n-2-i]
    
if counter>10**9+7:
  counter=counter%(10**9+7)
print(counter)