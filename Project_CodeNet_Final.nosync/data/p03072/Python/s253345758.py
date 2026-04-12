n=int(input())
li = list(map(int,input().split()))

res = 1
for i in range(1,n):
	ll=li[:i]
	if max(ll)<=li[i]:
		res = res + 1

print(res)