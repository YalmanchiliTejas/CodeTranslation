import sys
import numpy as np
input = sys.stdin.readline

def main():
    N = int(input())
    s = [input().strip() for i in range(N)]

    count = np.zeros((N, ord("z") - ord("a") + 1), dtype=int)

    for i in range(N):
        for c in s[i]:
            count[i][ord(c) - ord("a")] += 1
    
    for i in range(1, N):
        count[i] = np.minimum(count[i], count[i-1])
    
    for i in range(len(count[-1])):
        print(chr(ord("a") + i) * count[-1][i], end="")
    print()

if __name__ == "__main__":
    main()