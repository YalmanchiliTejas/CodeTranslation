A,B,C,X,Y=map(int,input().split())

if X>=Y:
    ans=min(2*C,A+B)*Y+min(A,2*C)*(X-Y)
else:
    ans=min(2*C,A+B)*X+min(B,2*C)*(Y-X)

print(ans)