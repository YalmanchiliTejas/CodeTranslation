n=int(input())
a=list(map(int,input().split()))
M=0
cnt=0
for i in range(n):
    if M<=a[i]:
        cnt+=1
        M=a[i]
print(cnt)