n=int(input())
lista=list(map(int,input().split()))
listb=[]
for i in lista:
	listb.append(i)
for i in range(1,n):
	listb[i]=listb[i]+listb[i-1]
# print(listb)
sum1=0
for i in range(n-1):
	sum1+=lista[i]*(listb[-1]-listb[i])
sum1=sum1%(1000000007)
print(sum1)