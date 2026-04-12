N = int(input())
A = list(map(int, input().split()))

mymod = 1000000007

def modpow(a, n):
    res = 1
    while(n > 0):
        if n & 1:
            res = (res*a)%mymod

        a = (a * a)%mymod
        n >>= 1

    return res

def modinv(a, b):
    return (a * modpow(b, mymod-2))%mymod

inv2 = modinv

Ai2_sum = 0
for Ai in A:
    Ai2 = (Ai**2)%mymod
    Ai2_sum = (Ai2_sum + Ai2)%mymod

sumA = sum(A)%mymod
sumA_2 = (sumA**2) % mymod

print(modinv(sumA_2 - Ai2_sum, 2))



