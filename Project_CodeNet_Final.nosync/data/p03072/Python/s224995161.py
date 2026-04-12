N = int(input())

*H, = map(int, input().split())
count = 0
flg = 1
for i in range(len(H)):
    flg = 1
    for j in range(0,i,1):
        if H[i]>=H[j]:
            continue
        else:
            flg = 0
            break
    if flg==1:
        count = count + 1
    
print(count)