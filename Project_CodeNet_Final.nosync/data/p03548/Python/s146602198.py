#! python3
# coding:utf-8

def main():
	X,Y,Z = input().split(' ')
	X,Y,Z = int(X),int(Y),int(Z)
	output = int((X - Z) / (Y + Z))
	print(output)
if __name__ == "__main__":
	main()