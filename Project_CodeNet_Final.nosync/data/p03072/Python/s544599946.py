ans = 0
mx = -1
n = int(input())
l = list(map(int,input().split()))
for i in range(n):
	if l[i] >= mx:
		mx = l[i]
		ans += 1
print(ans)        
        