N = int(input())
A = list(map(int, input().split()))
p = 10**9+7
sumA = 0
sumsq = 0
for i in range(len(A)):
  a = A[i]
  sumA += a
  sumA = sumA%p
  sumsq += pow(a, 2, p)
  sumsq = sumsq%p
sqsum = pow(sumA, 2, p)
if sqsum < sumsq:
  sqsum += p
if (sqsum - sumsq)%2 != 0:
  sqsum += p
ans = (sqsum - sumsq)//2
print(ans)