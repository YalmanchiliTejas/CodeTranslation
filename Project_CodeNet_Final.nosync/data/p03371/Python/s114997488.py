A,B,C,X,Y = map(int,input().split())

res = A * X + B * Y
for i in range(2, 4 * (X + Y) + 1,2):
	curr = max(0,A * (X - i // 2)) + max(0,B * (Y - i // 2)) + C * i
#	print(i,curr) 
	res = min(res, curr)

print(res)