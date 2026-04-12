a,b,c,x,y=map(int,input().split())
if max(x,y)==x:
  large=a
  small=b
else:
  large=b
  small=a
kingaku=0
if a+b>=2*c:
  kingaku+=2*c*min(x,y)
  if large>=2*c:
    kingaku+=2*c*(max(x,y)-min(x,y))
  else:
    kingaku+=large*(max(x,y)-min(x,y))
else:
  kingaku+=a*x+b*y

print(kingaku)
