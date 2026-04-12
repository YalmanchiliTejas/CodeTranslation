h,w=map(int,input().split())
g=[input() for _ in range(h)]
a=['' for _ in range(h)]
for y in range(w):
  if any(s[y]=='#' for s in g):
    for x in range(h):
      a[x]+=g[x][y]
for s in a:
  if s.count('#'): print(s)