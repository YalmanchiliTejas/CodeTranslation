n=int(input())
a=[]
for i in range(n):
	a.append(int(input()))
a.sort()
ans1=ans2=0
p=q=a[n//2]
if n%2==0:
	for i in range(n//2-1):
		ans1+=abs(p-a[i])
		p=a[i]
		ans1+=abs(p-a[-i-1])
		p=a[-i-1]
	ans1+=abs(p-a[n//2-1])
	print(ans1)
else:
	for i in range(n//2):
		ans1+=abs(p-a[i])
		p=a[i]
		ans1+=abs(p-a[-i-1])
		p=a[-i-1]
		ans2+=abs(q-a[-i-1])
		q=a[-i-1]
		ans2+=abs(q-a[i])
		q=a[i]
	print(max(ans1,ans2))


