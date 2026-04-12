H,W=map(int,input().split())
A=[list(input())for i in range(H)]
ww=set()
hh=set()
for h in range(H):
  for w in range(W):
    if A[h][w]=='#':
      ww.add(w)
      hh.add(h)
ww=sorted(list(ww))
for h in sorted(list(hh)):
  _=''
  for w in ww:
    _+=A[h][w]
  print(_)