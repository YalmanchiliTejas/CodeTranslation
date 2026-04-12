A,B,C,X,Y=map(int, input().split())

if X>=Y:ans,Ccnt=C*X*2,X*2
else:ans,Ccnt=C*Y*2,Y*2

for c in range(1,Ccnt//2+1):
	
	temp=(Ccnt-2*c)*C
	if (Ccnt-c*2)//2<Y:
		temp+=(Y-(Ccnt-c*2)//2)*B
	if (Ccnt-c*2)/2<X:
		temp+=(X-(Ccnt-c*2)//2)*A
	#print(X-(Ccnt-c*2)/2,Y-(Ccnt-c*2)/2,Ccnt-2*c,temp)
	ans=min(ans,temp)

print(ans)