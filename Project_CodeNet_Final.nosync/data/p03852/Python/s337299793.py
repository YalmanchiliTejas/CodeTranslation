INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
def do():
    boin = ('a','e','u','i','o')
    c = STR()
    if c in boin:
        print('vowel')
    else:
        print('consonant')
if __name__ == '__main__':
    do()