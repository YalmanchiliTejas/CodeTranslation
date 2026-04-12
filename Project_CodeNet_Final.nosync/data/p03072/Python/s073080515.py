n = int(input())
h = input().split()
 
ans = 1
m = n-1
high = int(h[0])
 
for i in range(m):
    if int(h[i+1]) >= high:
        ans += 1
        high = int(h[i+1])
    else:
        continue
        
 
print(ans)