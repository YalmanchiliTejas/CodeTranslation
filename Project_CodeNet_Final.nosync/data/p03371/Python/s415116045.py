
A,B,C,X,Y = list(map(int,input().split()))
max_pizza=max(X,Y)#AピザとBピザのうち、必要な枚数の多い方のピザの枚数
ans=10E+10  

for i in range(0,max_pizza*2+2,2):#ABピザをi枚買う(iは偶数)
    #max_pizza*2+2の「+2」に注意。例えばrange(0,10,2)
    #のとき0,2,4,6,8までしか出てこない。(0,10+2,2)なら10まで出る

    if (X-i/2)<=0 and (Y-i/2)>0:
        ans_kouho = B*(Y-i/2)+C*(i)
    elif (X-i/2)>0 and(Y-i/2)<=0:
        ans_kouho = A*(X-i/2)+C*(i)
    elif (X-i/2)<=0 and(Y-i/2)<=0:
         ans_kouho = C*(i)
    else:
        ans_kouho = A*(X-i/2)+B*(Y-i/2)+C*(i)

    
    if(ans_kouho<ans):
        ans = ans_kouho

print(int(ans))

