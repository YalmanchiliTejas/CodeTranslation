while True:
  N=int(input())
  if N==0:
    break
  s=list(int(input())for i in range(N))

  s.sort()
  del s[0]
  del s[-1]

  s_ave=sum(s)/len(s)
  print(int(s_ave))
