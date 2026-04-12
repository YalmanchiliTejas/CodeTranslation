import sys
input = sys.stdin.readline
#import math #python 3.5~
import fractions #fractions.gcd() python~3.4
sys.setrecursionlimit(1000000)

def main(): 
    N = int(input())
    H = list(map(int,input().split()))
    max=H[0]
    ans=1
    for i in range(1,N):
        if max <= H[i]:
            ans+=1
            max=H[i]
    print(ans)


if __name__ == "__main__":
    main()
    