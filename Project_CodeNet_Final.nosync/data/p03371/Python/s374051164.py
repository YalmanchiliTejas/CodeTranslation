A,B,C,X,Y = map(int,input().split())

ave = (A+B)//2
#個別で買う or 組み合わせて不足分を買う or 組み合わせて余る　

ans1 = A*X + B * Y

ans2 = min(X,Y)*C*2
if X > Y:
    ans2 += (X-Y) * A
elif Y > X:
    ans2 += (Y-X) * B

ans3 = max(X,Y)*C*2

print(min(ans1,ans2,ans3))