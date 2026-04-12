def i():
	return int(input())
def i2():
	return map(int,input().split())
def s():
	return str(input())
def l():
	return list(input())
def intl():
	return list(int(k) for k in input().split())

a,b,c,x,y = i2()

ans = float("inf")
note = 0
for i in range(0,2*max(x,y)+1,2):
	note = a*max(0,x-i//2)+b*max(0,y-i//2)+c*i
	ans = min(ans,note)
print(ans)