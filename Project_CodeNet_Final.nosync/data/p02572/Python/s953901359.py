n = int(input())
a = list(map(int,input().split()))
sumlist = [0]*(n-1)
cursum = 0
for i in range(n-1):
  cursum += a[n-1-i]
  sumlist[n-2-i] = cursum
totalsum = 0
for j in range(n-1):
  totalsum += a[j]*sumlist[j]
print(totalsum%((10**9)+7))