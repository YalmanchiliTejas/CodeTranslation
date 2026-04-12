a,b,c=list(map(int,input().split()))
d=100*a+10*b+c
print("YES" if d%4==0 else "NO")