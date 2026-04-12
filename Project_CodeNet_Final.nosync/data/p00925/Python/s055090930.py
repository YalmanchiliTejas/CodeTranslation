def lr_op(expr, length):
	op = {"+": lambda x,y : x + y, "*": lambda x,y : x * y }
	result = expr[0]
	inc = 1
	while inc < length:
		result = op[expr[inc]](result,expr[inc+1])
		inc += 2
	return result
inputs = raw_input()
length = len(inputs)
expr = [int(inputs[i]) if i % 2 == 0 else inputs[i] for i in range(length)]
bob = int(raw_input())
L = lr_op(expr, length)
inc = 1
while inc < length:
	if expr[inc] == "*":
		expr[inc] = expr[inc-1] * expr[inc+1]
		for i in range(2):
			del expr[inc-1+i]
		length -= 2
	else :
		inc += 2
M = lr_op(expr, length)
if M == bob:
	print "U" if L == bob else "M"
else :
	print "L" if L == bob else "I"