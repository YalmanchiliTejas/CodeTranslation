# -*- coding: utf-8 -*-
def solve():
    X = int(input())
    if X in (3,5,7):
        return 'YES'
    else:
        return 'NO'    
if __name__ == '__main__':
    print(solve())