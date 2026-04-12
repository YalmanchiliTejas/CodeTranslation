import math
for i in range(50):
	n,l,r=map(int,input().split())
	if n==0 and l==0 and r==0:
		break
	else:
		a=[]
		for ii in range(n):
			a.append(int(input()))
		ans=0
		

		for k in range(l,r+1):

			for s in range(math.ceil(n/2)):
				if k%a[2*s]==0:
					ans+=1
					break
				elif 2*s+1==n :
					break
				elif k%a[2*s+1]==0:
					break
				elif s==math.ceil(n/2)-1 and n%2==0:
					ans+=1
					break
				else:
					continue

					


		print(ans)

