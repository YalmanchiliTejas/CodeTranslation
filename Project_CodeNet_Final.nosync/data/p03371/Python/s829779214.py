s=list(map(int,input().split()))
a=0
if s[0]+s[1]>=2*s[2]:
  b=min(s[3],s[4])
  a+=(b*s[2]*2)
  s[3]-=b
  s[4]-=b
  if s[3]==0:
    if s[1]>=2*s[2]:
      a+=2*s[2]*s[4]
    else:
      a+=s[1]*s[4]
  else:
    if s[0]>=2*s[2]:
      a+=2*s[2]*s[3]
    else:
      a+=s[0]*s[3]
else:
  if s[0]>=2*s[2]:
    a+=2*s[2]*s[3]
    a+=s[1]*s[4]
  else:
    if s[1]>=2*s[2]:
      a+=2*s[2]*s[4]
      a+=s[0]*s[3]
    else:
      a+=s[0]*s[3]
      a+=s[1]*s[4]
print(a)