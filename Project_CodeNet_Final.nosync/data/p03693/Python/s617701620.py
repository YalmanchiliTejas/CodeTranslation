a,b,c=map(int,input().split())
num=a*100+b*10+c
print("YES" if num%4==0 else "NO")