n = int(input())
h = list(map(int,input().split()))
flag = 1
cnt = 0
for i in range(n):
    for j in range(i+1):
        if h[i]>=h[j]:
            flag = 1
        else:
            flag = 0
            break
    if flag == 1:
        cnt+=1
print(cnt)
