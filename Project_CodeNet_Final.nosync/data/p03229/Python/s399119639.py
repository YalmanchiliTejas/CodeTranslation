# coding: utf-8
# Your code here!

S = int(input())
lis = []
for item in range(0,int(S)):
    tmp = input()
    lis.append(int(tmp))
ls = sorted(lis)
#print(ls)
#print(ls[int(S/2)])
i = 1
lo = 0
hg = int(S)-1
ans2 = 0
if True:#S % 2 == 1 :
    ans =  ls[hg]- ls[int(S/2-0.5)]
    #print(ans)
    for k in range(0,int(S/2)+1):
        #print(i)
    # TODO: write code...
    # TODO: write code...
    # TODO: write code...
        #if(k != 0):
        #    hg-=1
        if(i == int(S)-1):
            break
        ans = ans + ls[hg] - ls[lo]
        i+=1
        #print(ls[hg],ls[lo])
        hg-=1
        #print(i)
        #print(ans)
        if(i == int(S)-1):
            break
        ans = ans + ls[hg] - ls[lo]
        #print(ls[hg],ls[lo])
        lo+=1
        i+=1
        #print(ans)
tmp1 = ans


if S % 2 == 1:
    ls = sorted(lis,reverse=True)
    #print(ls)
    lo = 0
    hg = int(S)-1
    ans2 =  ls[int(S/2)]-ls[hg]
    #print(ans2)
    i = 1
    for k in range(0,int(S/2)+1):
        #print(i)
    # TODO: write code...
    # TODO: write code...
    # TODO: write code...
        #if(k != 0):
        #    hg-=1
        if(i == int(S)-1):
            break
        ans2 = ans2 + ls[lo]-ls[hg]
        i+=1
        #print(ls[hg],ls[lo])
        hg-=1
        #print(i)
        #print(ans)
        if(i == int(S)-1):
            break
        ans2 = ans2 +  ls[lo]-ls[hg]
        #print(ls[hg],ls[lo])
        lo+=1
        i+=1




print(max(ans2,tmp1))
 #   hg-=1
 #   print(ls[hg] , ls[lo])
 #   ans= ans + (ls[hg] - ls[lo])
 #   print(ans)
 #   ans = ans + (ls[hg] - ls[lo])
 #   lo+=1
 #   hg-=1
 #   print(ls[hg] , ls[lo])
 #   print(ans)
