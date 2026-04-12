N = int(input())
As = list(map(int,input().split()))
sums = 0
moder = 1000000007
s=[0 for i in range(N-1)]
s[-1] = As[-1]
for i in range(N-2):
  s[-(i+2)] = s[-(i+1)]+As[-(i+2)]

for i in range(N-1):
  sums+= (As[i]*s[i])%moder
print(sums%moder)