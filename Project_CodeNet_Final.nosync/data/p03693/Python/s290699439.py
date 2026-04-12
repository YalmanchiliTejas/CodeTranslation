R,G,B = map(int,input().split())
print("YES" if (100*R+10*G+B)%4==0 else "NO")