while True:
    n=int(input())
    if n==0:break
    com=[int(input())for i in range(n)]
    seq=[1]
    isW=com[0]==0
    stW=isW
    for i in range(1,n):
        if i%2!=0:
            if len(seq)!=1:
                if (isW and com[i]==1)or(not isW and com[i]==0):
                    seq[len(seq)-2]+=seq.pop()+1
                else:seq[len(seq)-1]+=1
            else:
                seq[0]+=1
                if (isW and com[i]==1)or(not isW and com[i]==0):stW=not stW
            isW=com[i]==0
        else:
            if isW:
                if com[i]==0:seq[len(seq)-1]+=1
                else:
                    seq.append(1)
                    isW=False
            else:
                if com[i]==0:
                    seq.append(1)
                    isW=True
                else:seq[len(seq)-1]+=1
    total=0
    if stW:total=sum(seq[0::2])
    else:total=sum(seq[1::2])
    print(total)