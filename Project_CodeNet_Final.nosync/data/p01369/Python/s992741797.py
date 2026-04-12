left = ['q','a','z','w','s','x','e','d','c','r','f','v','t','g','b']
right= ['y','h','n','u','j','m','i','k','o','l','p']

while True:
	hand = 0
	count = 0
	string = str(raw_input())
	if string == "#":
		break
	
	for var in range(0, len(string)):
		if string[var:var+1] in left:
			if hand != 1:
				hand = 1
				count += 1
		elif string[var:var+1] in right:
			if hand != 2:
				hand = 2
				count += 1
				
	print count - 1