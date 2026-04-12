A,B,C,X,Y = (int(i) for i in input().split())  
ans = 0
if C*2 <= A+B:
	for i in range(min(X,Y)):
		ans += C*2
		X-=1
		Y-=1
	ans += min(C*2, A)*X
	ans += min(C*2, B)*Y
else:
	ans += A*X
	ans += B*Y
print(ans)