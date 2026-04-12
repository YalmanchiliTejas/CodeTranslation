S = int(input())
n = list(map(int, input().split()))

tmp = n[0]
sum1=1
for i in range(1,S):
  if tmp <= n[i]:
    tmp=n[i]
    sum1=sum1+1
print(sum1)