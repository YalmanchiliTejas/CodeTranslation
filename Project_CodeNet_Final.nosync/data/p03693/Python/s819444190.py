a,b,c = map(int,input().split())
S = 100*a+10*b+c
print("YES" if S%4==0 else "NO")
