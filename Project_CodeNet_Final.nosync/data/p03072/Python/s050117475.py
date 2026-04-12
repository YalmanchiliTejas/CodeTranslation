n = int(input())
h = list(map(int, input().split()))
max_mount = h[0]
ans = 0 
for i in range(n):
    if max_mount<=h[i]:
    	ans +=1
    	max_mount = h[i]
print(ans)