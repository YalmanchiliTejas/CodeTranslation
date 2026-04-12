N, X = map(int, input().split())

lst = [1]

for _ in range(1,N+1):
  lst.append(2*lst[-1]+1)

pw = 2**(N+1)-3
rlt = 0
i = N-1
while 1:
  if X == 1:
    print(rlt)
    exit()
  elif X < pw+2:
    X -= 1
    pw = (pw-3)//2
    if i > 0: 
      i -= 1
    elif i == 0:
      print(rlt+1)
      exit()
  elif X == pw+2:
    rlt += lst[i]+1
    print(rlt)
    exit()
  elif X < 2*pw+3:
    X -= pw + 2
    pw = (pw-3)//2
    if i > 0:
      rlt += lst[i]+1
      i -= 1
    elif i == 0:
      print(rlt+3)
      exit()
  elif X == 2*pw+3:
    rlt += 2*lst[i]+1
    print(rlt)
    exit()