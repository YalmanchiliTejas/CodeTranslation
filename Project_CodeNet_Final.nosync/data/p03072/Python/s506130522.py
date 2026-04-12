import atexit
import io
import sys

buff = io.BytesIO()
sys.stdout = buff


@atexit.register
def write():
    sys.__stdout__.write(buff.getvalue())

n = input()
l = map(int, raw_input().split())
ans = 0
for i in xrange(n):
	valid = 1
	for j in xrange(i):
		if l[j] > l[i]:
			valid = 0
			break
	if valid:
		ans += 1
print ans