n,x=map(int,input().split())
s=[1]*(n+1)
a=[1]*(n+1)
for i in range(1,n+1):
  s[i]=s[i-1]*2+3
  a[i]=a[i-1]*2+1
def p(l,d):
  if l==0:
    if d==0:
      return 0
    else:
      return 1
  elif d<=l:
    return 0
  elif d<=s[l-1]+1:
    return p(l-1,d-1)
  elif d<=s[l-1]*2+2:
    return a[l-1]+1+p(l-1,d-s[l-1]-2)
  else:
    return a[l]
print(p(n,x))