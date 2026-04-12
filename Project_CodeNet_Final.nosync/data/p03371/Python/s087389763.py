# 入力

A, B, C, X, Y=map(int, input().split())
numA=0
numB=0
numC=0
answer=0

if A>2*C:
    #Aを買うくらいならCを2個買うべき
    answer+=2*X*C #ABピザを、Aを充足する分購入する
    numC+=2*X
    Y-=X #その分Bも買った
    X=0

if B>2*C and Y>0:
    #Bを買うくらいならCを2個買うべき
    answer+=2*Y*C #ABピザを、Bを充足する分購入する
    numC+=2*Y
    X-=Y #その分Aも買った
    Y=0

if X>0 or Y>0: #まだどちらかを買う必要があるなら
    if A+B>2*C: #AとBを1個ずつ買うくらいならCを2個買うべき
        answer+=2*min(X, Y)*C
        numC+=2*min(X, Y)
        m=min(X, Y)
        X-=m
        Y-=m

    answer+=A*X+B*Y
    numA+=X
    numB+=Y

# print('A:'+str(numA)+' B:'+str(numB)+' C:'+str(numC))
print(answer)
