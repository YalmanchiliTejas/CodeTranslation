A, B, C, X, Y = map(int,input().split())
pattern1 = X*A + Y *B
pattern2 = X*(C*2) + B*(max(0,Y-X))
pattern3 = A*(max(0,X-Y)) + Y*(C*2)
print(min(pattern1,pattern2,pattern3))