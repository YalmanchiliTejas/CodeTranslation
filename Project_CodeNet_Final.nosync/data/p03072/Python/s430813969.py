N = int(input())

H = list(map(int, input().split()))

mount = 0
cnt = 0

for i in range(N) : 
    if(mount <= H[i]) : 
        cnt += 1
        mount = max(mount, H[i])
    
print(cnt)