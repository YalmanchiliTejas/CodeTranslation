A,B,C,X,Y = list(map(int,input().split()))

if C*2 <= A+B:
    ans = 0
    ans += C*2*min(X,Y)
    ans += min(A,C*2)*(X-Y) if Y<X else min(B,C*2)*(Y-X)
    print(ans)
else:
    print(A*X+B*Y)