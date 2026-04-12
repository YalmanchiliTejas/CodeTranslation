A,B,C,X,Y=map(int,input().split())
check=[0]*4
check[0]=A*X+B*Y
check[1]=C*max(X,Y)*2
check[2]=C*Y*2+A*(X-Y) if X>Y else float('inf')
check[3]=C*X*2+B*(Y-X) if X<Y else float('inf')
print(min(check))
