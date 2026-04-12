N = int(input())

As = [int(input()) for _ in range(N)]
As.sort()

rlt = 0

if len(As) % 2 == 1:
  tmp1 = 0
  tmp2 = 0
  b = len(As)//2
  for i in As[:b]:
    tmp1 -= 2*i
  for i in As[b:]:
    tmp1 += 2*i
  tmp1 -= As[b]
  tmp1 -= As[b+1]
  
  for i in As[:b+1]:
    tmp2 -= 2*i
  for i in As[b+1:]:
    tmp2 += 2*i
  tmp2 += As[b]
  tmp2 += As[b-1]
  if tmp1 > tmp2:
    rlt = tmp1
  else:
    rlt = tmp2

else:
  b = len(As)//2
  for i in As[:b]:
    rlt -= 2*i
  for i in As[b:]:
    rlt += 2*i
  rlt += As[b-1]
  rlt -= As[b]
  
print(rlt)