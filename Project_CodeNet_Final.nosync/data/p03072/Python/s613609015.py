N = int(input())
H = list(map(int,input().split()))
count = 1
for i in range(1,N,1):
    flag = True
    for j in range(0,i,1):
        if H[j] > H[i]:
            flag = False
            break
    if flag == True:
        count += 1
print(count)