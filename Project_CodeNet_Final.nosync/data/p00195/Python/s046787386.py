while True:
  a,b = map(int,input().split(" "))
  if a == 0 and b == 0: break  
  c,d = map(int,input().split(" "))
  e,f = map(int,input().split(" "))
  g,h = map(int,input().split(" "))
  i,j = map(int,input().split(" "))  

  listsum= [a+b,c+d,e+f,g+h,i+j]
  listsum.sort()
   
  if listsum[-1] == a+b:
    print("A",listsum[-1]) 
  elif listsum[-1] == c+d:
    print("B",listsum[-1]) 
  elif listsum[-1] == e+f:
    print("C",listsum[-1]) 
  elif listsum[-1] == g+h:
    print("D",listsum[-1]) 
  elif listsum[-1] == i+j:
    print("E",listsum[-1])

