def main():


	l = list(str(input()))

	ans = 0
	for i in range(len(l)-1):
		if l[i] != l[i+1]:
			ans += 1
	if ans > 0:
		print("Yes")
	else:
		print("No")
	

if __name__ == '__main__':
	main()