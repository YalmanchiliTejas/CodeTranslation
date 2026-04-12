icase=0
if icase==0:
    n=int(input())
    h=list(map(int,input().split()))
    hh=h[0]
    icnt=1
    for i in range(1,n):
        if hh<=h[i]:
            icnt+=1
        hh=max(hh,h[i])
    print(icnt) 
      