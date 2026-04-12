n=int(input())
h=list(map(int,input().split()))
max_num=h[0]
cnt=1
for i in range(1,len(h)):
    if h[i]>=max_num:
        cnt+=1
        max_num=h[i]
print(cnt)