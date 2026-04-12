N=int(input())
A=list(map(int,input().split()))

sum = 0
multiplicand=A[0]
for a in A[1:]:
  sum+=multiplicand*a
  multiplicand+=a
print(sum%((10)**9+7))