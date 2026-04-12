#100点問題　abc064 a-rgbcards
r,g,b=map(int,input().split())
print("YES" if (10*g+b)%4==0 else "NO")