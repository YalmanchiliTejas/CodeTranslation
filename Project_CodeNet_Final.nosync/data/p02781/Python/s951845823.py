from math import factorial as fac

def comb(n,r):
    if ( r<0 or r>n ):
        return 0
    return fac(n)/(fac(r)*fac(n-r))


n=int(input())
k=int(input())

nn=str(n)
keta=len(nn)

ans=0

if keta<k:
    print(0)
    exit()

zero=0

# for i in range(keta):
#     if int(nn[i])==0:zero+=1
#     ans+=comb(keta-i-1,k-i+zero)*9**(k-i)
#     if int(nn[i])-1>=0:
#         ans+=(int(nn[i])-1)*comb(keta-i-1,k-i-1+zero)*9**(k-i-1+zero)
#
# if keta-zero==k:ans+=1

def search(n,k):
    if k<=0:return
    global ans
    nn = str(n)
    keta = len(nn)
    ans += comb(keta - 1, k ) * 9 ** k
    if int(nn[0])-1>0:
        ans+=(int(nn[0])-1)*comb(keta-1,k-1)*9**(k-1)
    ne=n-int(nn[0])*10**(keta-1)
    search(ne,k-1)


search(n,k)
for i in range(keta):
    if nn[i]=="0":zero+=1
if keta-zero>=k:ans+=1
print(int(ans))