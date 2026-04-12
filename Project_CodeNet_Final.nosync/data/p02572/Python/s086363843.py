MOD = 10**9 + 7
n = int(input())
A = list(map(int, input().split()))

import numpy
A_CS = numpy.cumsum(sorted(A, reverse=True))
A_CS = A_CS%MOD

A = sorted(A)

#print(A_CS)
ans = 0
for i in range(n-1):
#    print(A[i], A_CS[-i-2])
#    A_CS -= A[i]
    ans = (ans+(A[i]*A_CS[-i-2])%MOD)%MOD
print(ans)