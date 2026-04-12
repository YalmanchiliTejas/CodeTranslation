N=int(input())
H=list(map(int,input().split()))
max=H[0]
cnt=0
for i in H:
    if i>=max:
        max=i
        cnt+=1
print(cnt)