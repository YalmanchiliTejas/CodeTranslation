n,x = map(int,input().split())

def layers(L):
  if L == 0:
    return 1
  else:
    return layers(L-1)*2+3
  
def patties(L,X):
  if L == 0:
    return 1
  elif X == 1:
    return 0
  elif X <= layers(L)//2:
    return patties(L-1,X-1)
  elif X == layers(L)//2+1:
    return layers(L-1)//2+2
  elif layers(L)//2+2 <= X <= layers(L)-1:
    return layers(L-1)//2+2+patties(L-1,X-layers(L)//2-1) 
  else:
    return layers(L)//2+1
    
print(patties(n,x))