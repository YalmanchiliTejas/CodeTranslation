from sys import stdin

def main():

    input = stdin.readline

    S = input()[:-1]


    if((S in 'AAA') or (S in 'BBB')):
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()