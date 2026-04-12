X,Y,Z = map(int,input().split())
answer = 0
X -= Y+2*Z
answer += 1
answer += X//(Y+Z)
print(answer)
