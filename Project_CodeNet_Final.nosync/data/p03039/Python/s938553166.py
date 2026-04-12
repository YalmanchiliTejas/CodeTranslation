import sys
range = xrange
input = raw_input

MOD = 10**9+7

def modinv(x):
    return pow(x,MOD-2,MOD)

def nck(n,k):
    a = 1
    b = 1
    c = 1
    for i in range(1,n+1):
        a = a*i%MOD
    for i in range(1,k+1):
        b = b*i%MOD
    for i in range(1,n-k+1):
        c = c*i%MOD
    return a*modinv(b*c%MOD)%MOD
        
n,m,k = [int(x) for x in input().split()]

inv = modinv(n*m)
m1inv = modinv(n*m-1)

ans = 0

def summer(x):
    return x*(x-1)//2

p = (k*inv%MOD)*(m1inv*(k-1)%MOD)%MOD

xfac = n*n*p%MOD
for xi in range(m):
    ans += xfac * summer(m-xi)%MOD

yfac = m*m*p%MOD
for yi in range(n):
    ans += yfac * summer(n-yi)%MOD
#for xi in range(m):
#    for yi in range(n):
#        ans += n*p%MOD * summer(m-xi)%MOD
#        ans += m*p%MOD * summer(n-yi)%MOD
        #for xj in range(m-xi):
        #    s = xj
        #    ans += n*s*p%MOD
        
        #for yj in range(n-yi):
        #    s = yj
        #    ans += m*s*p%MOD
        
        #for xj in range(m):
        #    for yj in range(n):
        #        s = abs(xi-xj) + abs(yi - yj)     
        #        ans += p*s%MOD
print nck(n*m,k)*ans%MOD
