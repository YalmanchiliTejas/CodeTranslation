# -*- coding: utf-8 -*-
"""
AtCoder B
"""

def main():
    N=input()
    S=list(map(str,input().split()))[0]
    K=int(input())

    trg= S[K-1]
    out=""
    for s in S:
        if s!=trg:
            out+="*"
        else:
            out+=s
    print(out)

if __name__ == "__main__":
    main()