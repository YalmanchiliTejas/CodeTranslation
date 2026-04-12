H,W=map(int,input().split())
a=[]
for _ in range(H):
  a.append(list(input()))

for i in range(H):
  is_in_black=False
  for j in range(W):
    if a[i][j]=='#':
      is_in_black=True
      break
  if is_in_black == False:
    for j in range(W):
      a[i][j]=0
  pass

for j in range(W):
  is_in_black=False
  for i in range(H):
    if a[i][j]=='#':
      is_in_black=True
      break
  if is_in_black == False:
    for i in range(H):
      a[i][j]=0
  pass

# print ans
for i in range(H):
  ans = ''
  for j in range(W):
    if a[i][j]!=0:
      ans+=a[i][j]
  if len(ans)!=0:
    print(ans)

