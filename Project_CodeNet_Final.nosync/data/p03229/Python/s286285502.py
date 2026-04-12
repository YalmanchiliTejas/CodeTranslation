N = int(input())
arr = [int(input()) for i in range(N)]
arr.sort()
m = N // 2

if N % 2 ==0:
  high = sum(arr[m:])
  low  = sum(arr[:m])
  print((high - low) * 2 - (arr[m] - arr[m-1]))
else:
  center = arr[m]
  high = sum(arr[m+1:])
  low = sum(arr[:m])
  dl = center - arr[m-1]
  dh = arr[m+1] - center
  if dl > dh:
    print((high - low) * 2 - dh)
  else:
    print((high - low) * 2 - dl)