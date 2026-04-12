ABCXY = input().split()
A,B,C,X,Y = int(ABCXY[0]),int(ABCXY[1]),int(ABCXY[2]),int(ABCXY[3]),int(ABCXY[4])
resultA = []
resultB = []
Min = float("inf")
if(X >= Y):
    taisyou = X*2
else:
    taisyou  = Y*2
    
for i in reversed(range(0, taisyou+1, 2)):
    #Xの枚数はX - i/2
    #Yの枚数はY- i/2
    if(X - i/2 <= 0):
        Xcount = 0
    else:
        Xcount = X-i/2
    if(Y - i/2 < 0):
        Ycount = 0
    else:
        Ycount = Y-i/2
    Min =  min(Min, i * C + Xcount* A + Ycount * B)
print(int(Min))