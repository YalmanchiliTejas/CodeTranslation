import math
K,A,B=map(int,input().split())
if A>=K:
    print(1)
else:
    if A<=B:
        print(-1)
    else:
        if (K-A)%(A-B)==0:
            print((K-A)//(A-B)*2+1)
        else:
            print((K-A)//(A-B)*2+3)