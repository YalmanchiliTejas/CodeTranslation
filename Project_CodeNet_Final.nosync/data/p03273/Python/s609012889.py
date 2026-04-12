INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))
def do():
    h,w=INTM()
    a=[]
    wd=[]
    for i in range(h):
        temp=STR()
        if temp!='.'*w:
            a.append(temp)
    h=len(a)
    for i in range(w):
        flg=1
        for j in range(h):
            if a[j][i]=='#':
                flg=0
        if flg==1:
            wd.append(i)
    wd=sorted(wd,reverse=True)
    for i in wd:
        for j in range(h):
            #print(i,j)
            a[j]=a[j][:i]+a[j][i+1:]
    for i in range(h):
        print(a[i],sep='')
        
    
if __name__ == '__main__':
    do()