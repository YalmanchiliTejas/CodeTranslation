N=int(input())
num=[int(input()) for i in range(N)]
num.sort()

if N%2!=0: #kisu
  manaka=int(N/2)  
  sum_a=abs(num[manaka]-num[N-1])
  sum_a+=abs(num[N-1]-num[0])
  for i in range(int((N-1)/2)-1):
    sum_a+=abs(num[N-2-i]-num[i])
    sum_a+=abs(num[i+1]-num[N-2-i])
  sum_b=abs(num[manaka]-num[0])
  sum_b+=abs(num[0]-num[N-1])
  for i in range(int((N-1)/2)-1):
    sum_b+=abs(num[i+1]-num[N-1-i])
    sum_b+=abs(num[i+1]-num[N-2-i])
  print(max(sum_a,sum_b))
else:
  manaka=int(N/2)
  sum=abs(num[manaka]-num[0])
  for i in range(manaka-1):
    sum+=abs(num[i]-num[N-1-i])
    sum+=abs(num[i+1]-num[N-1-i])
  print(sum)