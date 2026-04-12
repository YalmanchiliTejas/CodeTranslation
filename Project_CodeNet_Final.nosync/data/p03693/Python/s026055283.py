a,g,b= map(int,input().split(" "))
RGB=100*a+10*g+b
print("YES" if RGB%4==0 else "NO")