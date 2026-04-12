input()
s=input()
k=s[int(input())-1]
print(''.join(['*'if c!=k else c for c in s]))