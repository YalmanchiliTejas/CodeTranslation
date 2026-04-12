INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    s=STR()
    s=set(s)
    if len(s)==1:
        print('No')
    else:
        print('Yes')
if __name__ == '__main__':
    do()