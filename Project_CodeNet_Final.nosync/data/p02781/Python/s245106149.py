
N=int(input())
K=int(input())

keta1=len(str(N))
maxN=int(str(N)[0])
secN=0
keta2=0
if keta1>1:
    keta2=len(str(int(str(N)[1:])))
    secN=int(str(int(str(N)[1:]))[0])
    if keta2>1:
        keta3=len(str(int(str(int(str(N)[1:]))[1:])))
        thiN=int(str(int(str(int(str(N)[1:]))[1:]))[0])
only1=0
only2=0
if secN==0:
    only1=1
if keta2>1:
    if str(int(str(int(str(N)[1:]))[0]))[0]==0:
        only2=1
import math

if keta1<K:
    print(0)
else:
    if K==1:
        print(maxN+9*(keta1-1))
    if K==2:
        if keta1-2!=0:
            if only1:
                print((maxN-1)*(keta1-1)*9+9**2*(keta1-2)*(keta1-1)//2)
            else:
                if keta2-1!=0:
                    print((maxN-1)*(keta1-1)*9+9**2*(keta1-2)*(keta1-1)//2+secN+(keta2-1)*9)
                else:
                    print((maxN-1)*(keta1-1)*9+9**2*(keta1-2)*(keta1-1)//2+secN)
        else:
            print((maxN-1)*(keta1-1)*9+secN)
    if K==3:
        if keta1-3!=0:
            if only1:
                print((maxN-1)*(keta1-1)*(keta1-2)//2*9**2+9**3*(keta1-3)*(keta1-2)*(keta1-1)//6)
            else:
                if keta2-2!=0:
                    print((maxN-1)*(keta1-1)*(keta1-2)//2*9**2+9**3*(keta1-3)*(keta1-2)*(keta1-1)//6+(secN-1)*9*(keta2-1)+9**2*(keta2-2)*(keta2-1)//2+thiN+(keta3-1)*9)
                else:
                    print((maxN-1)*(keta1-1)*(keta1-2)//2*9**2+9**3*(keta1-3)*(keta1-2)*(keta1-1)//6+(secN-1)*9*(keta2-1)+9**2*(keta2-2)*(keta2-1)//2+thiN)
        else:
            if only1:
                print((maxN-1)*(keta1-1)*9)
            else:
                print((maxN-1)*(keta1-1)*9+(secN-1)*9+thiN)


