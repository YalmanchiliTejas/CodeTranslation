n=int(input())
h=list(map(int,input().split()))
cnt=0
for i in range(n):
    if max(h[0:i+1])==h[i]:
        cnt+=1
print(cnt)