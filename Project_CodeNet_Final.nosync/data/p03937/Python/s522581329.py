n,m=map(int,input().split())
arr=[input() for _ in range(n)]
for i in range(n-1):
  if (m-1)-arr[i][::-1].index('#')>arr[i+1].index('#'):
    print('Impossible')
    break
else:
  print('Possible')
