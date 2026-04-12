H, W = map( int, input().split())

a = []
b = []
c = []

for i in range(H):
  a1 = input()
  if('#' in a1):
     a.append(a1)
        
  else:
      continue

a = list(zip(*a))
l1 = len(a)
         
for j in range(l1):
  b1 = a[j]
   
  if( '#' in b1):
      b.append(b1)
  
  else:
      continue
         
c = list(zip(*b))
l2 = len(c)

for n in range(l2):
         print("".join(c[n]))