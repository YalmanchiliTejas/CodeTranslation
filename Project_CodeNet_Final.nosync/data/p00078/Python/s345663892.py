for e in iter(input,'0'):
 n=int(e);m,f=[[0]*n for _ in[0]*n],'{:4}'*n
 j=n//2;i=j+1
 m[i][j]=1
 for k in range(2,n*n+1):
  i,j=-~i%n,-~j%n
  if m[i][j]:i,j=-~i%n,~-j%n
  m[i][j]=k
 for r in m:print(f.format(*r))
