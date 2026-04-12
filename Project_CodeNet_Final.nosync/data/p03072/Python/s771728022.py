n = int(input())
H = list(map(int,input().split()))
ans = 0
for i in range(n):
	if H[i]>=max(H[:i+1]):
		ans += 1
         
print(ans)