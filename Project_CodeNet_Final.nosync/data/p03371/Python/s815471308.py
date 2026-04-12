A,B,C,X,Y=map(int,input().split())
if X>Y:
  answer=min(C*X*2,A*X+B*Y,C*Y*2+A*(X-Y))
elif X<Y:
  answer=min(C*Y*2,A*X+B*Y,C*X*2+B*(Y-X))
else:
  answer=min(C*X*2,A*X+B*Y)
print(answer)