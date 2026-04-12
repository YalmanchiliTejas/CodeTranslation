import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    s = readline().strip()

    if s == "BBB" or s == "AAA":
        print("No")
    else:
        print("Yes")



if __name__ == "__main__":
    main()
