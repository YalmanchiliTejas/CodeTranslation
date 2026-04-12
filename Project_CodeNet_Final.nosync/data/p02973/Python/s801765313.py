a=int(input())
b=[int(input()) for i in range(a)]
LIS = [b[0]]
for i in range(1,len(b)):
  if b[i] <= LIS[-1]:
    LIS.append(b[i])
  else:
    lo=0
    hi=len(LIS)
    while lo < hi:
      mid=(lo+hi)//2
      if b[i]>LIS[mid]:
        hi =mid
      else:
        lo=mid+1  
    LIS[lo] = b[i]
print(len(LIS))