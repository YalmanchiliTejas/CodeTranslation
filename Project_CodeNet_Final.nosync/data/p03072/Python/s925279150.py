N = int(input())
H = list(map(int,input().rstrip().split()))

total = 1
flg = True
for i in range(1,N):
    for j in range(i):
        if H[j] > H[i]:
            flg = False
            break
    if flg:
        total += 1
    else:
        flg = True
        
print(total)