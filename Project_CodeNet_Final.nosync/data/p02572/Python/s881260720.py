n = int(input())
arr  = input().split(" ")
s = int(arr[-1])
mod = 10**9 +7
ans  = 0

def moduloMultiplication(a, b, mod): 
    res = 0; 
    a = a % mod; 
    while (b): 
        if (b & 1): 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
  
        b >>= 1;
      
    return res; 

for i in range(len(arr)-2, -1, -1):
    t = int(arr[i])
    ans = (ans+  moduloMultiplication(s,t,mod))%mod
    s = (s+t)
print( ans)