# -*- coding: utf-8 -*-

def main(N, H):
    count = 1
    max = H[0]
    for i in range(1, N):
        if(H[i]>=max):
            count += 1
            max = H[i]
            
    print(count)

if __name__ == '__main__':
    N = int(input())
    H = [int(h) for h in input().split()]
    
    main(N, H)