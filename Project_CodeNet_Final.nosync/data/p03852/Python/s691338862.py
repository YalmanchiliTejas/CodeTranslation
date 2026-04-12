# -*- coding: utf-8 -*-
import sys
import re
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

def main():
    if re.match(r'[aeiou]',input()):
        print('vowel')
    else:
        print('consonant')
    

if __name__ == '__main__':
    main()
