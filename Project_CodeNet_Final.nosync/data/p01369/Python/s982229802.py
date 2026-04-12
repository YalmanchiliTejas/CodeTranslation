def main():
	while True:
		cmd = input()
		if cmd == "#":
			return
		right = "qwertasdfgzxcvb"
		count = 0
		isr =  cmd[0] in right
		for c in cmd[1::]:
			if c in right and not isr:
				count += 1
				isr = not isr
			if not c in right and isr:
				count += 1
				isr = not isr
		print(count)
				

if __name__ == '__main__':
	main()
