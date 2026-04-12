# -*- coding: utf-8 -*-
"""
AtCoder B
"""

def main():
    N=list(map(int,input().split()))
    H=list(map(int,input().split()))
    
    max_h=0
    num=0
    for h in H:
        if max_h<=h:
            max_h=max(max_h,h)
            num+=1
    print(num)

if __name__ == "__main__":
    main()