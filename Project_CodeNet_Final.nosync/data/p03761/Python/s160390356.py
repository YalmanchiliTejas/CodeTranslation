import sys
from string import ascii_lowercase as alphabets
from collections import Counter

def main():
    inf=100
    alphd={x:0 for x in alphabets}
    ansd={x:inf for x in alphabets}
    n=int(input())
    s=[input() for _ in range(n)]
    for st in s:
        for x in st:
            alphd[x]+=1
        for a in alphabets:
            ansd[a]=min(ansd[a],alphd[a])
            alphd[a]=0
    print(''.join([a*ansd[a] for a in alphabets if ansd[a]<inf]))
    

def main2():
    inf=100
    n=int(input())
    s=[Counter(input()) for _ in range(n)]
    ansd={x:inf for x in alphabets}
    for c in s:
        for x in alphabets:
            ansd[x]=min(ansd[x],c[x])
    print(''.join([a*ansd[a] for a in alphabets if ansd[a]<inf]))

if __name__=='__main__':
    main2()
