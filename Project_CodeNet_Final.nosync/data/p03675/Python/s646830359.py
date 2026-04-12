
if __name__ == "__main__":
	n = int(input())
	num_array = input().split(" ")
	result = [0 for i in range(n)]
	for i in range(n)[::-1]:
		differ = n - (i + 1)
		if differ % 2 == 0:
			result[differ // 2] = num_array[i]
		else:
			result[- ((differ + 1) // 2)] = num_array[i]
	result_word = result[0]
	for w in result[1:]:
		result_word += " " + w
	print(result_word)