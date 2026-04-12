import itertools

left = 'qwertasdfgzxcvb'
while True:
	s = input()
	if s == '#':
		break
	print(len([k for k, g in itertools.groupby([c in left for c in s])])-1)