H,W=map(int,input().split())

l=[]
for i in range(H):
  x=input()
  # 白いマスのみからなる場合は追加しない
  if x!='.'*W:
    l.append(x)

rm=[]
for i in range(W):
  # フラグ
  f=True
  for j in range(len(l)):
    if l[j][i]=='#':
      f=False

  # 取り除く列の添字を保存しておく
  if f:
    rm.append(i)

a=[]
for x in l:
  for i in rm[::-1]:
    x=x[:i]+x[i+1:]
  a.append(''.join(x))

# 出力
for i in range(len(a)):
  print(''.join(a[i]))