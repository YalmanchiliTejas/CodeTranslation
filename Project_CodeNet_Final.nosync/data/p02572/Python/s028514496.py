N = int(input()); MOD = pow(10,9)+7
A = list(map(int,input().split()))
S = sum(A)**2%MOD
nijo = 0
for x in A:
  nijo = (nijo + x**2)%MOD
ans = (S-nijo)*pow(2,MOD-2,MOD)%MOD
print(ans%MOD)