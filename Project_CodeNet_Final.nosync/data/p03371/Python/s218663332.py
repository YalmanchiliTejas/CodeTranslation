A,B,C,X,Y=map(int,(input().split()))
D=A if X>Y else B
print(min([A*X+B*Y,C*(max(X,Y))*2,(C*(min(X,Y))*2)+(D*((max(X,Y))-(min(X,Y))))]))