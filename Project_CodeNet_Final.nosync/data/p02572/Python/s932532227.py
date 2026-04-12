n=int(input())
M=10**9+7
X=list(map(int, input().split()))

tot = 0
s_tot=0

def modpow( a , n , m):
    ans=1
    n_bit = bin(n)[2:]
    l=len(n_bit)
    for i in list(range(l))[::-1]:
        if n_bit[i]=="1":
            ans = (ans * a) % m
        #print(i , n_bit[i] , a , ans)
        a=(a*a) %m
        #print(a,ans)
    return ans
inv_2 = modpow( 2 , M-2 , M)
for i in range(n):
    y=X[i]
    
    tot = (tot + y) % M
    s_tot = (s_tot + y**2%M ) % M

ans= ((tot ** 2 - s_tot )* inv_2 ) % M
print(ans)