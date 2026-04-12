

n = 0
a = []

def format_input(filename = None):
	global n
	global a
	if filename == None:
		n = int(input())
		a = list(map(int, input().split()))

	elif filename == '__random__':
		from random import randint as rng
		n = rng(2, 2 * 10**5)
		a = [rng(-1 * 10**9, 10**9) for i in range(n)]
		print(n)
		print(' '.join(list(map(str, a))))

def get_answer():
	odd = [0]
	even = [0]
	for i in range(n // 2):
		odd.append(odd[-1] + a[2*i])
		even.append(even[-1] + a[2*i+1])
	if n % 2 == 1:
		odd.append(odd[-1] + a[-1])

	answer = -1 * 10**9 * n
	if n % 2 == 0:
		for i in range(n // 2 + 1):
			answer = max(answer, odd[i] - even[i] + even[-1])
	else:
		even_range = [even[0] - odd[1]]
		for i in range(n // 2):
			add = a[2*i+1] - a[2*i+2]
			min = - a[2*i] + add
			even_range.append(max(even_range[-1] + add, min))
		answer = odd[-1] + max(even_range)
	return answer

if __name__ == '__main__':
	format_input()

	ans = get_answer()
	print(ans)
