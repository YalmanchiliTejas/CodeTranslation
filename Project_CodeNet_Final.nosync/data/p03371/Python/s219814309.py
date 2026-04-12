import sys
INFTY=sys.maxsize

def readinput():
    a,b,c,x,y=list(map(int,input().split()))
    return a,b,c,x,y

def main(a,b,c,x,y):
    minPrice=INFTY
    for nab in range(0,max(x,y)*2+1,2):
        na=max(0,x-nab//2)
        nb=max(0,y-nab//2)
        price=nab*c+na*a+nb*b
        #print(price, na, nb, nab)
        minPrice=min(minPrice,price)  
    return minPrice  

if __name__=='__main__':
    a,b,c,x,y=readinput()
    ans=main(a,b,c,x,y)
    print(ans)
