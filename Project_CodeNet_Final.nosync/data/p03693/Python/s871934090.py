r,g,b = map(int,input().split())

N = r * 100 + g * 10 + b

print("YES" if N%4==0 else "NO")