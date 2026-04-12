N = int(input())
A= list(map(int,input().split()))
mod_num = int(1.0e+9 + 7)
rest = 0
temp = 0

for i in range(N-1):
  temp+=A[i]
  rest += temp*A[i+1]
  rest = rest%mod_num

print(int(rest%mod_num))