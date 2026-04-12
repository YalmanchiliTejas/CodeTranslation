# coding: utf-8
import math

def str_intersection(w1, w2):
	s1 = set(w1)
	s2 = set(w2)
	set_intersection = s1.intersection(s2)
	result = ''
	for letter in set_intersection:
		num = min(w1.count(letter), w2.count(letter))
		result += letter*num
	return result


if __name__ == "__main__":
	n = int(input())
	s = []
	result = input()
	for _ in range(n-1):
		result = str_intersection(result, input())

	print(''.join(sorted(result)))
