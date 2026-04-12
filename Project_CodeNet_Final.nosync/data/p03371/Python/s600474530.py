def resolve():
    import sys
    input = sys.stdin.readline    
    a,b,c,x,y=map(int,input().split())
    z=min(x,y)
    ans=min(a*x+b*y,a*(x-z)+b*(y-z)+c*z*2,max(x,y)*2*c)
    print(ans)

if __name__ == '__main__':
    resolve()