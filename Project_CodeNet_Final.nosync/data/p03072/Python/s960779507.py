import numpy as np

def main():
    n = int(input())
    h = list(map( int, input().split()))

    kosuu = 1
    for i in range(n):
        if i > 0:
            if h[i]>=h[i-1]:
                if h[i] >= np.max(h[0:i]):
                    kosuu += 1
    print(kosuu)
    
    
if __name__ == '__main__':
    main()