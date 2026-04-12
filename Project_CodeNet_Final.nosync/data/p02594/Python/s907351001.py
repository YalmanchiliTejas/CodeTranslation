from math import *

def cin(): # To take limited number of inputs
    return map(int,input().split())

def cins(): # To take space sepreated strings
    return input.split()

def cino(test=False): # To take individual int input (test = False)
    if not test:
        return int(input())
    else: # To take string input (test = True)
        return input()

def cina(): # array input
  return list(map(int,input().split()))

def ssplit(): # multiple string input
    return list(input().split())

def printlist(l): # To print space seperated array
    for i in l:
        print(i,end=" ")

def main():
    a = cino()
    # s = cino(True)
    # a,b = cin()
    print("Yes" if a>= 30 else "No")

if __name__ == '__main__':
    main()