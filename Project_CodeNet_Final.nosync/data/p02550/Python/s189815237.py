import sys
input = sys.stdin.readline

N,X,M=map(int,input().split())
LIST=[X]
SET={X}

a=X

while True:
    if a*a%M in SET:
        break
    else:
        a=a*a%M
        LIST.append(a)
        SET.add(a)

l=LIST.index(a*a%M)
LEN=len(LIST)

if N<=LEN:
    print(sum(LIST[:N]))
else:
    ANS=sum(LIST[:l])
    N-=l
    LIST=LIST[l:]
    S=sum(LIST)

    r,q=divmod(N,len(LIST))

    print(ANS+S*r+sum(LIST[:q]))
    

