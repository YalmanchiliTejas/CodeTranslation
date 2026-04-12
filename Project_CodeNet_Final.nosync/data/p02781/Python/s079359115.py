import math

def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def calc(n, k):
    if n < 10**(k-1):
        ans = 0
    elif n == 0:
        ans=0
    else:
        ans = 0
        digits = int(math.log10(n))+1
        #Nより小さい桁数
        if k <= digits-1:
            for n_dig in range(k, digits):
                ans += 9 * combinations_count(n_dig-1,k-1) * (9**(k-1))
                #print(n_dig,tot)
        #Nと桁数が同じ
        top = n//10**(digits-1)
        ans += (top-1) * combinations_count(digits-1,k-1) * (9**(k-1))
        if k>1:
            ans += calc(n-top*10**(digits-1), k-1)
        elif k==1:
            ans += 1
    #print(n,k,ans)
    return ans
    

N = int(input())
K = int(input())

tot = calc(N,K)

print(tot)
    
