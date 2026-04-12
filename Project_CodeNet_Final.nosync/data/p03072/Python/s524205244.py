from fractions import gcd

N = int(input())
H = list(map(int, input().split()))
max = 0
c = 0
for i in range(N):
  if H[i]>=max:
    c += 1
    max = H[i]
print(c)