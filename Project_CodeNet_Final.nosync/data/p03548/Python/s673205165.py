X,Y,Z = map(int,input().split())
X -= Y+2*Z
answer = 1
while X >= Y+Z :
    X -= Y+Z
    answer += 1
print(answer)
