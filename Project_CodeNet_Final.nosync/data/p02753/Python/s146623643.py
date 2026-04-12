import sys

x = sys.stdin.readline()

a=0
b=0

for i in x:
  if ( i == 'A'):
    a = 1
  if ( i == 'B'):
    b = 1

if( a == 1 and b == 1):
	print "Yes"
else:
	print "No"

sys.stdout.flush()
