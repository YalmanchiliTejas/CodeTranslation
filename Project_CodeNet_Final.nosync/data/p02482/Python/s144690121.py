a, b = [int(f) for f in raw_input().split()]
if a == b:
	result = '=='
elif a > b:
	result = '>'
else:
	result = '<'
print 'a', result, 'b'