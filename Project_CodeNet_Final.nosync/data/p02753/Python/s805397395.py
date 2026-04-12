S=input()
S=[1 if s=='A' else 0 for s in S]
print("No") if sum(S)==0 or sum(S)==3 else print("Yes")