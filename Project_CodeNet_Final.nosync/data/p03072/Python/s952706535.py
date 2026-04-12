n = int(input())
h = list(map(int,input().split()))
hmax = 0
cnt = 0
for i in range(n):
    if(hmax<=h[i]):
        hmax = h[i]
        cnt += 1
    
print(cnt)