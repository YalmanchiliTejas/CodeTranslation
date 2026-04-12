import math
from datetime import date

def main():

	n = int(input())
	s = input()
	k = int(input())
	k -= 1

	ans = ""
	for c in s:
		if c == s[k]:
			ans += s[k]
		else:
			ans += "*"

	print(ans)

main()
