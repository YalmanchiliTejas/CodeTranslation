n = int(input())
l = list(map(int,input().split()))
M = 1000000007
sm = 0
for i in l:
	sm = (sm + i)
sms = pow(sm,2)
ss = 0
for i in range(n):	
	ss = (ss + (l[i] * l[i]))
print(((sms - ss)//2)%M)