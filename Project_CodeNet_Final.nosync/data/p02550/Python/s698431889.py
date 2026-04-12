N,X,M = map(int, input().split())

check = [0]*(M+1)
SUM1 = 0
cnt1 = 0
temp = X
check3=0
for i in range(N):

    if check[temp]==0:
        check[temp]+=1
    else:
        check3 = 1
        break
        
    SUM1 += temp
    cnt1 += 1
    temp = temp ** 2
    temp %= M


check2 = [0]*(M+1)
SUM2 = 0
cnt2 = 0
if check3==1:
    
    for i in range(N):


        if check2[temp]==0:
            check2[temp]+=1
        else:
            break
        SUM2 += temp        
        cnt2 += 1
        temp = temp ** 2
        temp %= M



SUM3 = 0

Y = (N-cnt1)%max(cnt2,1)

for i in range(Y):
    
    SUM3 += temp

    temp = temp ** 2
    temp %= M
    
if check[0]==1:
    SUM3=0
    N = cnt1+cnt2

print(SUM1+SUM2*(((N-cnt1)//max(cnt2,1)))+SUM3)