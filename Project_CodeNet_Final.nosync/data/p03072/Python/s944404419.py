INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    n=INT()
    hs=LIST()
    ct=0
    for i in range(n):
        if max(hs[0:i+1])==hs[i]:
            ct+=1
    print(ct)
if __name__ == '__main__':
    do()