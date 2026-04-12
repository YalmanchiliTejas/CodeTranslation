n, x = list(map(int, input().split()))

def length_burger(k):
	if k == 0:
		return(1)
	else:
		return(2*length_burger(k-1) + 3)

def num_pate(k, s):
	if s <= 0:
		return 0
	elif k == 0:
		return 1
	else:
		middle = length_burger(k) // 2 + 1
		if s < middle:
			return num_pate(k - 1, s - 1)
		elif s == middle:
			return num_pate(k - 1, s - 2) + 1
		else:
			if s == length_burger(k):
				return 2 * num_pate(k - 1, middle - 2) + 1
			else:
				return num_pate(k - 1, middle - 2) + 1 + num_pate(k - 1, s - middle)

print(num_pate(n, x))