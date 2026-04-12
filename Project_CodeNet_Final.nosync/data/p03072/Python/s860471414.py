#!/usr/bin/env python
import logging
logging.basicConfig(level=logging.DEBUG)
logging.disable(logging.CRITICAL)

def main():
    N = int(input())
    H = list(map(int, input().split()))
    
    ans = 1
    for i in range(1, N):
        flag = 0
        for j in range(i):
            if H[i] < H[j]:
                flag += 1
            else:
                continue
        logging.debug('flag: {}'.format(flag))
        if flag == 0:
            ans += 1

    return ans

if __name__ == '__main__':
    print(main())

