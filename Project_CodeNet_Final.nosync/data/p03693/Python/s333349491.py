a,b,c = map(int, input().split())
n = a*100+b*10+c
print("YES" if n%4==0 else "NO")