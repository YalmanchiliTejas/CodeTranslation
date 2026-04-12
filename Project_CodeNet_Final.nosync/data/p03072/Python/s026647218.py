n=int(input())
h=list(map(int, input().split()))
m=h[0]
cnt=0
for i in range(n):
    if m<=h[i]:
        m=h[i]
        cnt+=1
print(cnt)