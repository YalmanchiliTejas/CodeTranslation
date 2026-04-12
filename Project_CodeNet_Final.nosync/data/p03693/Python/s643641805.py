r,g,b=map(int,raw_input().split())
if (2*g + b) % 4 == 0:
  print 'YES'
else:
  print 'NO'