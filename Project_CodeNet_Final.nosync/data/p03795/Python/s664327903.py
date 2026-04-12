import sys

for x in map(int, [x.strip() for x in sys.stdin]):
	price = x*800
	discount = x/15*200
	print price-discount