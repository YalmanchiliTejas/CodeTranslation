N = int(input())
A = list(map(int,input().split()))
s = 0
s2 = 0
P = 10**9 + 7
for i in range(N):
    s = ( s + A[i] )%P
    s2 = (s2 + (A[i]**2) % P ) % P
r2 = pow(2, P-2, P)
print( ( (  ( s**2 % P - s2 ) % P ) * r2 ) % P)