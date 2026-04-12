while True:
  n=int(input())
  if n==0:
    break
  else:
    max_s=0
    min_s=2000
    sum_s=0
    for i in range(n):
      s=int(input())
      sum_s=sum_s+s
      if s<min_s:
        min_s=s
      if s>max_s:
        max_s=s
    print((sum_s-max_s-min_s)//(n-2))
