N=input()
N=int(N)
L=[]

def diff(L):
    total=0
    for i in range(len(L)-1):
        total+=abs(L[i+1]-L[i])
    return total
for i in range(N):
    A=input()
    L.append(int(A))
L.sort()
if len(L)>3:
    length=len(L)
    SL=L[:int(length/2)]
    LL=L[int(length/2):]
    result=[]
    result.append(SL[-1])
    SL.pop(-1)
    last=LL[0]
    LL.pop(0)
    while True:
        try:
            result.append(LL[-1])
            LL.pop(-1)
            result.append(SL[0])
            SL.pop(0)
        except:
            break
    if abs(result[-1]-last)>=abs(result[0]-last): 
        result.append(last)
    else:
        result.insert(0,last)
    print(diff(result))
elif len(L)==3:
    all=[diff([L[0],L[1],L[2]]),diff([L[0],L[2],L[1]]),diff([L[1],L[0],L[2]]),diff([L[1],L[2],L[0]]),diff([L[2],L[0],L[1]]),diff([L[2],L[1],L[0]])]
    print(max(all))
elif len(L)==2:
    print(abs(L[0]-L[1]))

