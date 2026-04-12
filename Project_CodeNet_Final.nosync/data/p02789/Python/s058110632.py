import sys

read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
inputs = sys.stdin.buffer.readlines


#mod=10**9+7
# rstrip().decode('utf-8')
# map(int,input().split())
#import numpy as np


def main():
	n,m=map(int,input().split())
	
	print("Yes" if n==m else "No")







if __name__ == "__main__":
	main()
