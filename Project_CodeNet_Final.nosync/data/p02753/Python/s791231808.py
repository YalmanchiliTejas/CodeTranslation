s=input()
ans=s.count('A')!=len(s) and s.count('B') !=len(s)
print("Yes" if ans else "No")
