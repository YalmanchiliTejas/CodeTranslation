h,w=map(int,input().split())
l=[]
for i in range(h):
  l.append(input())
for i in range(h-1):
  for j in range(w-1):
    if l[i][j]=='#'and l[i][j+1]=='#'and l[i+1][j]=='#'and l[i+1][j+1]=='#':
      print('Impossible')
      exit()
    if l[i][j]=='.'and l[i][j+1]=='#'and l[i+1][j]=='#'and l[i+1][j+1]=='#':
      print('Impossible')
      exit()
    if l[i][j]=='#'and l[i][j+1]=='#'and l[i+1][j]=='#'and l[i+1][j+1]=='.':
      print('Impossible')
      exit()
print('Possible')