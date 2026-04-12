
N=input()
N=int(N)

As=[]
for i in range(N):
	As.append(int(input()))


As.sort()

l=[]
l.append(As[N//2])
#if(N%2==0):
s=0
b=0
for i in range(N-1):
	if(i%2==1):
		l.append(As[-b-1])
		b+=1
	else:
		l.append(As[s])
		s+=1
ans=0
for i in range(1,N):
	ans+=abs(l[i]-l[i-1])
#print(l)
#print(ans)

l2=[]
l2.append(As[(N-1)//2])
#if(N%2==0):
s2=0
b2=0
for i in range(N-1):
	if(i%2==0):
		l2.append(As[-b2-1])
		b2+=1
	else:
		l2.append(As[s2])
		s2+=1
ans2=0
for i in range(1,N):
	ans2+=abs(l2[i]-l2[i-1])
#print(l2)
#print(ans2)
print(max(ans,ans2))