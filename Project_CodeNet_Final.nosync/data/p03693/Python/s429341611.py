r,g,b=map(int,input().split())

n=r*100+g*10+b

print("YES" if n%4==0 else "NO")