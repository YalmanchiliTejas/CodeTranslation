from sys import stdin, stdout
from math import floor
def IL():return list(map(int, stdin.readline().split()))

def main():
    
    x,y,z = IL()
    x -= z
    print(floor(x/(y+z)))
if __name__ == "__main__": main()