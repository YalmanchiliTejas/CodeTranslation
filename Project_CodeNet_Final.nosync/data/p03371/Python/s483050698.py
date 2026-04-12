# AtCoder Beginner Contest 095
# C - Half and Half

A,B,C,X,Y=map(int,input().split())
if X>Y: 
    X,Y=Y,X
    A,B=B,A
                # ここまでで、X<=Yが保証された


nomal=X*A+Y*B
buyCuntilX=2*X*C+(Y-X)*B
allC=2*X*C+(Y-X)*2*C

print(min(nomal,buyCuntilX,allC))