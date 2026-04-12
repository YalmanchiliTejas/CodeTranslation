N=int(input())
h=list(map(int, input().split()))
cnt=0
max_high=0

for i in range(N):
    if h[i]>=max_high:
        max_high=h[i]
        cnt+=1
        
print(cnt)