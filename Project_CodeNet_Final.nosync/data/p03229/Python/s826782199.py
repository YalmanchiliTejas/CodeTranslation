n = int(input())
a = sorted(list(map(int, [input() for i in range(n)])), reverse=True)
if n % 2 == 0:
  print(2*sum(a[:int(n/2)])-2*sum(a[-int(n/2):])-a[int(n/2-1)]+a[int(n/2)])
else:
  x = 2*sum(a[:int((n-1)/2)])-2*sum(a[-int((n-1)/2):])-a[int((n-1)/2)]+a[int((n-1)/2+1)]
  y = 2*sum(a[:int((n-1)/2)])-2*sum(a[-int((n-1)/2):])+a[int((n-1)/2)]-a[int((n-1)/2-1)]
  if x > y:
    print(x)
  else:
    print(y)