def count(keta,kazu):
    if(keta<kazu):
        return 0
    result=1
    wari=1
    for i in range(kazu):
        wari*=i+1
        result*=keta-i
    result//=wari
    #print(result)
    for i in range(kazu):
        result*=9
    return result


def Ans(moji,kazu):
    #print(moji,kazu)
    naga=len(moji)
    if(naga<kazu):
        return 0
    if(kazu==0):
        return 1
    sento=int(moji[0])
    if(naga==1):
        return sento
    #return Ans(moji[1:],kazu)+Ans(moji[1:],kazu-1)+count()
    if(sento==0):
        plus=Ans(moji[1:],kazu)
        return plus
    else:
        plus=Ans(moji[1:],kazu-1)
        #print(count(naga-1,kazu),count(naga-1,kazu-1),plus)
        return count(naga-1,kazu)+count(naga-1,kazu-1)*(sento-1)+plus

n=input()
l=len(n)
k=int(input())


print(Ans(n,k))

#ans=count(l-1,k)
#print(ans)
#batu=0
#for i in range(l):
#    suji=int(n[i])
#    if(suji!=0):
#        batu+=1
#    if(k<batu):
#        break
#    nok=count(l-i-1,k-batu)
#    print(suji,nok)
#    ans+=nok*(suji-1)

#print(ans)