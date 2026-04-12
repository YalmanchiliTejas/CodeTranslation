red,green,brue = map(int,input().split())
total = 100*red+10*green+brue 
print("YES" if total % 4 == 0 else "NO")