# -*- coding: utf-8 -*-

def solve(c):
    if(c=="a" or c=="i" or c=="u" or c=="e" or c=="o"):
        print("vowel")
    else:
        print("consonant")


if __name__ == '__main__':
    c = input()  

    solve(c)