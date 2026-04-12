from sys import stdin
import sys
#stdin = open("input.txt")

if __name__ == "__main__":
    if int("".join(stdin.readline().split()))%4==0:
        print("YES")
    else:
        print("NO")