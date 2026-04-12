A,B,C,X,Y = list(map(int,input().split()))

if A+B <= 2*C:
  #only buy A and B
  print(X*A+Y*B)

else:
  if X >= Y and A < 2*C:
    #print("A")
    select = A
  elif X < Y and B < 2*C:
    #print("B")
    select = B
  else:
    #print("C")
    select = 2*C
    
  print((min(X,Y)*2*C)+ (abs(X-Y)*select))