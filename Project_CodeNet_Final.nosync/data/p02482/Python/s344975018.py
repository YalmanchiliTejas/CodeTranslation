import sys;

a, b = map(int, sys.stdin.readline().strip().split())
if a > b:
  print "a > b"
elif a < b:
  print "a < b"
else:
  print "a == b"