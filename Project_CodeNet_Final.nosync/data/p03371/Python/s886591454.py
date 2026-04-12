def main():
    from sys import stdin
    a,b,c,x,y = map(int,stdin.readline().rstrip().split())

    p1 = a*x+b*y
    p2 = max(x,y)*c*2
    p3 = min(x,y)*c*2+max(x-y,0)*a+max(y-x,0)*b
    print(min(p1,p2,p3))
main()