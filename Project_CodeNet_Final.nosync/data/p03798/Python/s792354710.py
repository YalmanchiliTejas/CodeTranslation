# -*- coding: utf-8 -*-
import sys

def main():
	n = int(input())
	tmp = input()
	ans = list(tmp)
	
	ans_Q = []
	case = [["." for _ in range(n)] for _ in range(4)]
	case[0][0] = "S"
	case[0][1] = "S"
	case[1][0] = "W"
	case[1][1] = "W"
	case[2][0] = "S"
	case[2][1] = "W"
	case[3][0] = "W"
	case[3][1] = "S"
	
	for case_o in case:
		for i in range(1, n-1):
			if case_o[i] == "S" and ans[i] == "o":
				case_o[i+1] = case_o[i-1]
				continue
			if case_o[i] == "S" and ans[i] == "x":
				case_o[i+1] = run(case_o[i-1])
				continue
			if case_o[i] == "W" and ans[i] == "o":
				case_o[i+1] = run(case_o[i-1])
				continue
			if case_o[i] == "W" and ans[i] == "x":
				case_o[i+1] = case_o[i-1]
				continue
				
		if case_o[n-1] == "S" and ans[n-1] == "o":
			if case_o[0] == case_o[n-2]:
				if case_o[0] == "S" and ans[0] == "o":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "S" and ans[0] == "x":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "o":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "x":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
		if case_o[n-1] == "S" and ans[n-1] == "x":
			if case_o[0] != case_o[n-2]:
				if case_o[0] == "S" and ans[0] == "o":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "S" and ans[0] == "x":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "o":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "x":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
		if case_o[n-1] == "W" and ans[n-1] == "o":
			if case_o[0] != case_o[n-2]:
				if case_o[0] == "S" and ans[0] == "o":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "S" and ans[0] == "x":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "o":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "x":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
		if case_o[n-1] == "W" and ans[n-1] == "x":
			if case_o[0] == case_o[n-2]:
				if case_o[0] == "S" and ans[0] == "o":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "S" and ans[0] == "x":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "o":
					if case_o[1] != case_o[n-1]:
						ans_Q = case_o
						break
				if case_o[0] == "W" and ans[0] == "x":
					if case_o[1] == case_o[n-1]:
						ans_Q = case_o
						break
	
	if len(ans_Q) == 0:
		print(-1)
	else:
		word = ""
		for w in ans_Q:
			word = word + w
		print(word)
	
def run(cher):
	if cher == "W":
		return "S"
	else:
		return "W"
		
if __name__ == "__main__":
	main()
	