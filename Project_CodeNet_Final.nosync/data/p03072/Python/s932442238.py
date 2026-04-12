n = int(input())
h = list(map(int,input().split()))


cnt=1 # h[0]
for i in range(1,n):
    flag=0
    for j in range(n):
        if i>j:
            # print(i,j,h[i],h[j])
            if h[i]>=h[j]:
                pass
            else:
                flag=1
    if flag == 0:
        cnt+=1

print(cnt)