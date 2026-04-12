def input_n(infile,outfile):
	while True:
		n = int(infile.readline())
		if n == 0:
			break
		dice(infile,outfile,n)

def dice(infile,outfile,n):
	point = 1
	top = 1
	east = 3
	south = 2
	for i in range(n):
		buff = top
		command = infile.readline().split()[0]
		if command == "North":
			point += south
			top = south
			south = (7 - buff)
		elif command == "South":
			point += (7 - south)
			top = (7 - south)
			south = buff
		elif command == "East":
			point += (7 - east)
			top = (7 - east)
			east = buff
		elif command == "West":
			point += east
			top = east
			east = (7 - buff)
		elif command == "Right":
			point += top
			remember = south
			south = east
			east = (7 - remember)
		elif command == "Left":
			point += top
			remember = east
			east = south
			south = (7 - remember)
		else:
			break
	print >> outfile,point

if __name__ == "__main__":
	import sys
	input_n(sys.stdin, sys.stdout)