import math
import itertools

INF = 10**9+7
n = 0
def main():
	n = int(input())
	s = [input() for i in range(n)]
	chr_list =  [INF for i in range(26)]
	for i in s:
		for j in range(26):
			chr_count = i.count(chr(97+j))
			if(chr_count < chr_list[j]): chr_list[j] = chr_count
	text = ''
	for i in range(26):
		text = text + chr(i+97) * chr_list[i]
	print(text)

main()
