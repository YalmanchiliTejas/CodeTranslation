import sys


# \n
def input():
    return sys.stdin.readline().rstrip()


def main():

    X =int(input())
    if X==1:
        print("NO")
        exit()
    if 105 % X ==0:
        print("YES")
    else:
        print("NO")





if __name__ == "__main__":
    main()
