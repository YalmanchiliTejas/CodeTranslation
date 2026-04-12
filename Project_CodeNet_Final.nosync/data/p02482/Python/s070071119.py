a, b = map(int, raw_input().split())
if a < b:
  str = "<"
elif a > b:
  str = ">"
else:
  str = "=="
print "a", str, "b"