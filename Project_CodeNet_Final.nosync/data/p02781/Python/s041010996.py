import sys 
N = list(input())
K = int(input())

L = len(N)
if K>L:
    print(0)
    sys.exit()
#%%
def cmb(l,k):
    if k<0 or l<0:
        return 0
    if k>L:
        return 0
    elif k==0 or l==0:
        return 1
    
    ret = l
    for i in range(k-1):
        ret *= (l-i-1)
    for i in range(k):
        ret //= (1+i)
    return ret


ans = 0
K2 = K
L2 = L
for i in range(L):
    if K2 < 0 or L2 < 0:
        break
    if N[i]=='0':
        L2 -= 1
        continue
    elif N[i]=='1':
        ans += 9**K2 * cmb(L2-1,K2)* int((L2-1)>0)
    else:
        ans += 9**K2 * cmb(L2-1,K2) * int((L2-1)>0)
        t = int(N[i])
        ans += (t-1)* 9**(K2-1) * cmb(L2-1,K2-1)
    K2 -= 1
    L2 -= 1

ttmp = 0
for a in N:
    if a!='0':
        ttmp+=1
if ttmp == K:
    ans += 1
print(int(ans))