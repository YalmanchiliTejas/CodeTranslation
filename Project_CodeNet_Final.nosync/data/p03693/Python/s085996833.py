r,g,a = map(int, input().split())


print("YES" if (g*10+a)%4==0 else "NO")