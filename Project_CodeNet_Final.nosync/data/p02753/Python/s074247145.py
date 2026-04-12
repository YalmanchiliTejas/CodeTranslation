import sys
input = sys.stdin.readline
input = sys.stdin.buffer.readline

def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def LI(): return list(map(int,input().split()))
def TI(): return tuple(map(int,input().split()))


def main():
    N = input()
    N = str(N)
    Sa = N.count("A")
    if Sa == 1 or Sa == 2:
        print("Yes")
    else:
        print("No")



if __name__ == "__main__":
	main()