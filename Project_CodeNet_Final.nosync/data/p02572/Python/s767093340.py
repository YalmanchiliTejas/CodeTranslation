MOD = int(1e9 + 7)
N = int(input())
A = list(map(int, input().split()))
rui = [A[0]]
for i in range(1,len(A)):
  rui.append((rui[-1]+A[i]) % MOD)


res = 0
for i in range(len(A)):
  res += A[i]*(rui[-1]-rui[i]) % MOD
  
print(res % MOD)
  