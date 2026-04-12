n=int(input())
h=list(map(int,input().split()))
h_max = 0
cnt=0
for i in range(n):
    if h[i]>=h_max:
        cnt+=1
        h_max=h[i]
print(cnt)