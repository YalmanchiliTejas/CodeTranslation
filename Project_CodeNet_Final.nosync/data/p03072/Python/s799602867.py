N = int(input())
H = [int(x) for x in input().split()]
cnt = 0
for index,i in enumerate(H):
    flag = True
    for j in range(index):
        if(H[j]>i):
            flag = False
    if(flag):
        cnt+=1
print(cnt)
