A,B,C,X,Y = map(int,input().split())

C *= 2
ans1 = A*X + B*Y
ans2 = C*X + B*max(0,Y-X)
ans3 = C*Y + A*max(0,X-Y)
print(min(ans1,ans2,ans3))