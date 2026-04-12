n,k = map(int,input().split())
result = 0
for b in range(k+1,n+1):
  roop = n //b
  roop_ok = (b-1) - (k-1)
  amari = n % b
  amari_ok = amari - k + 1
  if roop_ok >= 0 :
    result += roop * roop_ok
    if amari_ok > 0 :
      result += amari_ok
      
if k == 0:
  print(n**2)
else:
  print(result)
  
    
  
  