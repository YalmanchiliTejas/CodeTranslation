INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    x=INT()
    if x==3 or x==5 or x==7:
        print('YES')
    else:
        print('NO')
if __name__ == '__main__':
    do()