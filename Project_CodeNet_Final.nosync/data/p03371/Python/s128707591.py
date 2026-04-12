A,B,C,X,Y=map(int,input().split())
print(min(C*X*2+max(0,B*(Y-X)),C*Y*2+max(0,A*(X-Y)),A*X+B*Y))