da = list(map(int,input().split()))
oka = 0
o = 0
p = 0
l = 0
k = 0
if da[3] <= da[4]:
  oka = da[3]
  o = da[4]
  p = da[4]-da[3]
  l = 1
  k = 0
elif da[4] <= da[3]:
  oka = da[4]
  o = da[3]
  p = da[3]-da[4]
  l = 0
  k = 1
if (da[0]*da[3] + da[1]*da[4]) >= (da[2]*o*2 + da[k]*p):
  if da[3] <= da[4]:
    print(da[2]*da[4]*2)
  else:
    print(da[2]*da[3]*2)
elif (da[0]*da[3] + da[1]*da[4]) >= (da[2]*oka*2 + da[l]*p):
  if da[3] <= da[4]:
    print(da[2]*da[3]*2 + da[1]*(da[4]-da[3]))
  else:
    print(da[2]*da[4]*2 + da[0]*(da[3]-da[4]))
else:
  print(da[0] * da[3] + da[1] * da[4])