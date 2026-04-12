# -*- coding: utf-8 -*-
import sys

def main():
	n = int(input())
	
	yen = n * 800
	wari = (n // 15) * 200
	
	print(yen - wari)
	
if __name__ == "__main__":
	main()
	