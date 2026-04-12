n=int(input())
a=list(map(int,input().split()))
b=sum(a)
l=[]
for i in range(len(a)-1):
  b-=a[i]
  l.append(a[i]*b)
print(sum(l)%(1000000007))
