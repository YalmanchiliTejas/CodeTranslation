import sys

input=sys.stdin.read().split()
a=1
b=2
c=3
d=5
e=4
f=6
x=1





for command in input[1:]:


  if command=='North':
    a,b,d,f,c,e=b,f,a,d,c,e
    x=x+a
  elif command=='South':
    a,d,f,b,c,e=d,f,b,a,c,e
    x=x+a
  elif command=='West':
    a,e,c,f,d,b=c,a,f,e,d,b
    x=x+a
  elif command=='East':
    a,e,c,f,b,d=e,f,a,c,b,d
    x=x+a
  elif command=='Right':
    c,d,e,b,a,f=d,e,b,c,a,f
    x=x+a
  elif command=='Left':
    c,b,e,d,a,f=b,e,d,c,a,f
    x=x+a
  else:
      print x
      a=1
      b=2
      c=3
      d=5
      e=4
      f=6
      x=1
  
  
 

 
 