n=int(input())
s=input()
l=s[n-1]+s+s[0]
assign=['S','W']
for i in assign:
  for j in assign:
    t=i+j
    for k in range(2,n):
      if s[k-1]=='o':
        if t[-1]=='S':
          t+=t[-2]
        else:
          if t[-2]=='S':
            t+='W'
          else:
            t+='S'
      else:
        if t[-1]=='S':
          if t[-2]=='S':
            t+='W'
          else:
            t+='S'
        else:
          t+=t[-2]
    t=t[n-1]+t+t[0]
    ok=True
    for u in range(1,n+1):
      if l[u]=='o':
        if t[u]=='S':
          if t[u-1]!=t[u+1]:
            ok=False
        else:
          if t[u-1]==t[u+1]:
            ok=False
      else:
        if t[u]=='S':
          if t[u-1]==t[u+1]:
            ok=False
        else:
          if t[u-1]!=t[u+1]:
            ok=False
    if ok:
      print(t[1:n+1])
      exit()
print(-1)