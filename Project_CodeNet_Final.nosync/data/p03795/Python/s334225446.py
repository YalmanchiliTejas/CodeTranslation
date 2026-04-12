INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
def do():
    n=INT()
    print(n*800-n//15*200)
if __name__ == '__main__':
    do()