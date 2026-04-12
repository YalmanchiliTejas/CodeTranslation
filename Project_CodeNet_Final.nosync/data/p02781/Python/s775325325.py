import math
from operator import mul
from functools import reduce

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

answer=0

n=int(input())
k=int(input())
now=n
keta=0
alist=[]
while now!=0:
    amari=now%10
    now=now//10
    alist.append(amari)
    keta+=1
alist.reverse()
zlist=[]
for al in range(len(alist)):
    if alist[al]!=0:
        zlist.append([al, alist[al]])

if k>keta:
    print(0)
else:
    moto=10**(keta-1)
    first=n//moto
    if k>=2:
        second=(n-first*moto)//(moto//10)
        if k>=3:
            third=(n-first*moto-second*(moto//10))//(moto//100)
    #print(keta)
    #print(first, second)
    if keta-1>=k:
        answer+=cmb(keta-1, k)*(9**k)
    answer+=max(first-1, 0)*cmb(keta-1, k-1)*(9**(k-1))
    if k==1:
        answer+=1
    elif k==2:
        if keta-1>=k and second!=0:
            answer+=cmb(keta-2, k-1)*(9**(k-1))
        answer+=cmb(keta-2, k-2)*max(second-1, 0)*(9**(k-2))
        if second!=0:
            answer+=1
        else:
            swit=0
            kaz=0
            for zl in zlist:
                if zl[0]>=1 and swit==0:
                    swit=zl[0]
                    kaz=zl[1]
            if swit!=0:
                answer+=(keta-swit-1)*9
                answer+=kaz
    else:
        if keta-1>=k and second!=0:
            answer+=cmb(keta-2, k-1)*(9**(k-1)) #30xxxx
        answer+=cmb(keta-2, k-2)*max(second-1, 0)*(9**(k-2)) #31xxxx, 32xxxx
        if keta-1>=k and third!=0 and second!=0:
            answer+=cmb(keta-3, k-2)*(9**(k-2)) #330xxx
        if second!=0:
            if keta-1>=k:
                if third!=0:
                    answer+=third
                else:
                    swit=0
                    keta2=0
                    kaz=0
                    for zl in zlist:
                        if zl[0]>=2 and swit<=0:
                            swit+=1
                            keta2=zl[0]
                            kaz=zl[1]
                    if swit>0:
                        answer+=(keta-keta2-1)*9
                        answer+=kaz
            else:
                if third!=0:
                    answer+=third
        else:
            if keta-1>=k:
                if True:
                    swit=0
                    keta2=0
                    kaz=0
                    for zl in zlist:
                        if zl[0]>=2 and swit<=1:
                            swit+=1
                            keta2=zl[0]
                            kaz=zl[1]
                    if swit>1:
                        answer+=(keta-keta2-1)*9
                        answer+=kaz
                    elif swit==1:
                        if keta2!=keta:
                            answer+=cmb(keta-keta2-1, 2)*81
            else:
                if third!=0:
                    answer+=third
    
    print(answer)