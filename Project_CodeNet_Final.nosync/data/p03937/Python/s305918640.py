H,W=map(int,input().split())
ans='Impossible'
j=0

for i in range(H):
  A=[x for x in input()]
  count=A.count('#')
  if i==0 and A[0]=='.':
    break
  try:
    if i>0 and '#' in A[:j]:
      break
    else:
      if i==0:
        if count!=A[:count].count('#'):
        	break
      elif count!=A[j:j+count].count('#'):
        break
  except:
    j+=(count-1)
    pass
  j+=(count-1)
else:
  ans='Possible'
print(ans)